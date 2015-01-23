OPT=O3

fast: 
	clear
	g++ md5_main.cpp -fopenmp -o md5_O3 -O3
	./md5_O3

all: 
	clear
	g++ md5_main.cpp -fopenmp -o md5
	./md5
	g++ md5_main.cpp -fopenmp -o md5_O1 -O1
	./md5_O1
	g++ md5_main.cpp -fopenmp -o md5_O2 -O2
	./md5_O2
	g++ md5_main.cpp -fopenmp -o md5_O3 -O3
	./md5_O3
	
