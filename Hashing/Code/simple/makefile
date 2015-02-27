FILE=md5_main_vectors
test:
	g++ -O3 md5_vectors_len1-6.cpp -fopenmp -o l1-6
	g++ -O3 md5_main_vectors.cpp -fopenmp -o l7  -mavx
	g++ -O3 md5_vectors_len8.cpp -fopenmp -o l8 -mavx
	g++ -O3 md5_vectors_len9.cpp -fopenmp -o l9 -mavx
	./l1-6
	./l7

benchmark:
	g++ md5_main.cpp -fopenmp -o md5pc_base
	time ./md5pc_base
	g++ $(FILE).cpp -fopenmp -o md5pc_O0 -mavx -O0
	time ./md5pc_O0
	g++ $(FILE).cpp -fopenmp -o md5pc_O1 -O1 -mavx -fomit-frame-pointer
	time ./md5pc_O1
	g++ $(FILE).cpp -fopenmp -o md5pc_O2 -O2 -mavx -fomit-frame-pointer
	time ./md5pc_O2
	g++ $(FILE).cpp -fopenmp -o md5pc_O3 -O3 -mavx -fomit-frame-pointer
	time ./md5pc_O3
fast: 
	clear
	g++ $(FILE).cpp -fopenmp -o $(FILE) -O3 -mavx
	time ./$(FILE)
all: 
	clear
	g++ $(FILE).cpp -fopenmp -o md5pc_base -mavx -O0
	time ./md5
	g++ $(FILE).cpp -fopenmp -o md5_O1 -O1 -mavx -fomit-frame-pointer
	time ./md5_O1
	g++ $(FILE).cpp -fopenmp -o md5_O2 -O2 -mavx -fomit-frame-pointer
	time ./md5_O2
	g++ $(FILE).cpp -fopenmp -o md5_O3 -O3 -mavx -fomit-frame-pointer
	time ./md5_O3
	