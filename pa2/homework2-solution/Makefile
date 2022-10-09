all: driver.o 
	g++ driver.o -o driver

driver.o: driver.cpp linkedStack.h
	g++ -c driver.cpp

clean:
	rm *.o all