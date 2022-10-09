main: driver.o node.o linkedlist.o
	g++ -std=c++11 -o driver.o node.o linkedlist.o

driver.o: driver.cpp 
	g++ -std=c++11 -c driver.cpp

node.o: node.cpp node.h
	g++ -std=c++11 -c node.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ -std=c++11 -c linkedlist.cpp

clean: 
	rm *.o
	rm *.exe 

# no templated clases in makesfiles and no interfaces