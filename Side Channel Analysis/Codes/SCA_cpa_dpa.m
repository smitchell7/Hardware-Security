%% dpa: function description
% function m_samp = dpa(register_write)

% DPA attack 
num_traces = 91840;
wave = zeros(num_traces,270);
gpio = zeros(num_traces,270);
% disp(['register write ' num2str(register_write)]);
for i = 1:num_traces
	f=['Side_channel/sample' strrep(num2str(zeros(1,5-length(num2str(i)))), ' ', '') num2str(i) '.mat'];
	load(f);
	wave(i,:) = 0.00008.*rec(1,:);
	gpio(i,:) = 0.08.*rec(2,:);
end
num_samples = num_traces/20;
wave_ave = zeros(num_samples,270);
gpio_ave = zeros(num_samples,270);	

for i = 1:20:num_traces
	wave_ave(floor(i/20)+1,:) = mean(wave(i:i+19,:));
	gpio_ave(floor(i/20)+1,:) = mean(gpio(i:i+19,:));
end

clearvars wave gpio;


filename = 'feistel.txt';
delimiter = ',';
startRow = 2;
formatSpec = '%f%f%f%[^\n\r]';
fileID = fopen(filename,'r');
textscan(fileID, '%[^\n\r]', startRow-1, 'ReturnOnError', false);
dataArray = textscan(fileID, formatSpec, 'Delimiter', delimiter, 'ReturnOnError', false);
fclose(fileID);

Feistel = dataArray{:, 2};
% format the data as: feistel(sample_number, key_guess)
feistel = uint32(reshape(Feistel,64,[]).'); 

% Read in the array of xor outputs. 
% There should be one row for each trace. 
filename = 'xor.txt';
formatSpec = '%f%f%[^\n\r]';
fileID = fopen(filename,'r');
dataArray = textscan(fileID, formatSpec, 'Delimiter', ',', 'WhiteSpace', '', 'EmptyValue' ,NaN,'HeaderLines' ,startRow-1, 'ReturnOnError', false);
fclose(fileID);

% samples by xor outputs. 1d array. 
% XOR = uint32(hex2dec(dataArray{:, 1})); 
XOR = uint32(dataArray{:, 2}); 

clearvars filename delimiter startRow formatSpec fileID dataArray ans Feistel;

% box_mask contains the masking for the s_boxes. 
box_mask = hex2dec(['40410100'; '08021002'; '20808020'; '02080201'; '01002084'; '10040408'; '80200840'; '04104010' ]);
box_mask = uint32(box_mask);

correct_key = [60 11 56 46 22 50 16 44];

%%

ham = zeros(8,64);
hamm = ham;
average_one = zeros(64,270);
average_zero = zeros(64,270);
figure
for sbox = 1:8
	for key = 0:63
		% perform the xor with every sample. 
		d_bit = bitxor( XOR, feistel(:,key+1)); 
		% mask off the dbit based on which sbox we're using
		masked = bitand(d_bit,box_mask(sbox));
		masked = masked(1:num_samples);
		masked_weight = disthamming(uint32(0),uint32(masked));
		% the hamming weight of the system
		trace_ones = (masked_weight == max(masked_weight));
		trace_zeros = (masked_weight == min(masked_weight));
		%average the ones 
		average_one(key+1,:) = mean(wave_ave(trace_ones,:));
		%average the zeros
		average_zero(key+1,:) = mean(wave_ave(trace_zeros,:));
	end
	result = average_one - average_zero;
	figure(sbox);
	plot(1:270,result(:,:)); 
	hold on; plot(1:270,result(correct_key(sbox)+1,:),'k-','LineWidth',3); hold off;
	% hold on; plot(correct_key(sbox),result(correct_key(sbox)+1,register_write),'k*'); hold off;
	set(get(gca,'XLabel'),'String','Time (Sample)');
	set(get(gca,'YLabel'),'String','Voltage ');

	title(['DPA Attack. Voltage difference between traces \\ sbox ' num2str(sbox) ', Key' num2str(correct_key(sbox))]);
	% print('-dpng',['images/1219dpa key' num2str(sbox) ' point' num2str(register_write) ]);
	matlab2tikz(['images/dpa_' num2str(sbox)])
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% CPA attack. 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure(3)
% 64 keys, calculate a key guess for each one. 

m_samp = zeros(270,8);

range = 1:num_samples;
guess = zeros(numel(range), 64);
for sbox = 1:8
	% mask the bits for the XOR. This doesn't change with key guesses
	masked_xor = bitand(XOR(range),(box_mask(sbox)));
	for key = 0:63
		% guess is the hamming distance between the feistel and xor. 
		% mask the bits for everything but the sbox
		masked_f = bitand(feistel(range,key+1),(box_mask(sbox)));
		guess_xor = bitxor(uint32(masked_f),uint32(masked_xor));

		% generate the hamming distance
		guess(:,key+1) = disthamming(uint32(guess_xor),uint32(0));

		% by the end of this, guess contains 64 hamming weights based on the key
		% for each trace. This calculation is repeated for each sbox. 
	end
	% Perform correlation
	Gcorr = corr(  double(wave_ave(range,:)), double(guess) );

	figure(sbox+8)
	plot(1:270,Gcorr(:,:)); 
	hold on; plot(1:270,Gcorr(:,correct_key(sbox)+1),'k-','LineWidth',2);hold off;

	title(['CPA Attack. sbox ' num2str(sbox) ' Key ' num2str(correct_key(sbox))]);
	set(get(gca,'XLabel'),'String','Time (Sample)');
	set(get(gca,'YLabel'),'String','Correlation coefficient');
	[~,I] = max(Gcorr(:)');
	m_samp(:,sbox) = I;
	matlab2tikz(['images/cpa_' num2str(sbox)])

end
