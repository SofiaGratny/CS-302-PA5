all:
	g++ -o driver driver.cpp
	./driver
	
sorts: driver.o
	g++ driver.o -o sorts

driver.o: driver.cpp selection.h bubble.h merge.h
	g++ -c driver.cpp

clean:
	del driver.o
