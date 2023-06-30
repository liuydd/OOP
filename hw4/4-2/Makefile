main: main.o graph.o node.o operation.o mymap.o operation_minus.o operation_plus.o
	g++ -std=c++11 -o main main.o graph.o node.o operation.o mymap.o operation_minus.o operation_plus.o
main.o: main.cpp
	g++ -c -std=c++11 -o main.o main.cpp 
graph.o: graph.cpp graph.h mymap.h node.h operation.h operation_minus.h operation_plus.h
	g++ -c -std=c++11 -o graph.o graph.cpp 
node.o: node.cpp node.h
	g++ -c -std=c++11 -o node.o node.cpp 
operation.o: operation.cpp operation.h node.h
	g++ -c -std=c++11 -o operation.o operation.cpp 
mymap.o: mymap.cpp mymap.h 
	g++ -c -std=c++11 -o mymap.o mymap.cpp 
operation_minus.o: operation_minus.cpp operation_minus.h operation.h
	g++ -c -std=c++11 -o operation_minus.o operation_minus.cpp
operation_plus.o: operation_plus.cpp operation_plus.h operation.h
	g++ -c -std=c++11 -o operation_plus.o operation_plus.cpp
clean:
	rm main *.o
