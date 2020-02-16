driver.run: driver.o
	g++ -o driver.run driver.cpp --std=c++11

driver.o: driver.cpp
	g++ -o driver.o driver.cpp --std=c++11


clean: 
	@rm -f *.o *.run

run: driver.run
	./driver.run
