graph: driver.o graph.o
	g++ driver.o graph.o -o graph

driver.o: driver.cpp graph.h # add driver-needed .h files here 
	g++ -c driver.cpp

graph.o: graph.cpp graph.h
	g++ -c graph.cpp

clean:
	rm *.o *.exe