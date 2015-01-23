FILE=md5_main
fast: 
	clear
	g++ $(FILE).cpp -fopenmp -o md5_O3 -O3
	time ./md5_O3

all: 
	clear
	g++ $(FILE).cpp -fopenmp -o md5
	time ./md5
	g++ $(FILE).cpp -fopenmp -o md5_O1 -O1
	time ./md5_O1
	g++ $(FILE).cpp -fopenmp -o md5_O2 -O2
	time ./md5_O2
	g++ $(FILE).cpp -fopenmp -o md5_O3 -O3
	time ./md5_O3
	
