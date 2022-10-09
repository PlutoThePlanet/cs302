priorityqueue: driver.o 
	g++ driver.o -o driver

driver.o: driver.cpp priorityarrayqueue.h arrayqueue.h # add driver-needed .h files here 
	g++ -c driver.cpp

clean:
	rm *.o priorityqueue