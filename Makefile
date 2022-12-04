main: main.o Profile.o Network.o
	g++ -o main main.o Profile.o Network.o

main.o: main.cpp 
	g++ -c main.cpp

tests: tests.o
	g++ -o tests tests.o

tests.o: tests.cpp
	g++ -c tests.cpp

Profile.o: Profile.cpp Profile.h
	g++ -c Profile.cpp

Network.o: Network.cpp Network.h
	g++ -c Network.cpp

clean:
	rm -f main tests Profile Network main.o Profile.o Network.o tests.o

