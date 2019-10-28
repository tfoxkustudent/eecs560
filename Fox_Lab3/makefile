main: main.o
	g++ -std=c++17 main.o -o main

main.o: main.cpp linkedList.hpp hash.hpp
	g++ -std=c++17 -c  main.cpp


clean:
	rm -f main *.o 
