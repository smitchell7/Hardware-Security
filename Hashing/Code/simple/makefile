FILE=md5_main_vectors
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
	