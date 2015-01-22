OPT=O3
md5: 
	clear
	g++ -$(OPT) md5_main.cpp cmd_line.cpp -fopenmp -o md5
	time ./md5 -i passwd
	md5sum passwd
