CXXFLAGS=-g -std=c++11
main: main.o List.o Node.o
	$(CXX) $(CXXFLAGS) -o main main.o List.o Node.o
ListTest.o: main.cpp List.h Node.h
List.o: List.cpp List.h Node.h
Node.o: Node.cpp Node.h

test: test.cpp main.o List.o Node.o
	$(CXX) $(CXXFLAGS) -o test test.cpp List.o Node.o
testL: testList.cpp main.o List.o Node.o
	$(CXX) $(CXXFLAGS) -o testL test.cpp List.o Node.o

clean:
	rm -f *.o main test testL
