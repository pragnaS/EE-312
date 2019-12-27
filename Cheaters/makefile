# target: dependencies
# <tab> rule

plagiarismChecker: main.o collisionMatrix.o hashtable.o
		g++ -o plagiarismChecker main.o collisionMatrix.o hashtable.o

main.o: main.cpp hashtable.h collisionMatrix.h
	g++ -c main.cpp

collisionMatrix.o: collisionMatrix.cpp collisionMatrix.h
		g++ -c collisionMatrix.cpp

hashtable.o: hashtable.cpp hashtable.h
		g++ -c hashtable.cpp