all: demo
demo: hash.h hash.cpp main.cpp 
	g++ -std=c++11 main.cpp hash.cpp -o demo
clean:
	rm demo *~