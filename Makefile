# Suggested Makefile for CSE_1325 Homework #9
CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

default: jade

all: main 

debug: CXXFLAGS += -g
debug: default

jade: main.o mainwin.o store.o product.o java.o donut.o *.h
	${CXX} ${CXXFLAGS} -o jade main.o mainwin.o store.o product.o java.o donut.o $(GTKFLAGS)
main.o: main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp $(GTKFLAGS)
mainwin.o: mainwin.cpp *.h
	${CXX} ${CXXFLAGS} -c mainwin.cpp $(GTKFLAGS)
product.o: product.cpp *.h
	${CXX} ${CXXFLAGS} -c product.cpp
java.o: java.cpp *.h
	${CXX} ${CXXFLAGS} -c java.cpp
donut.o: donut.cpp *.h
	${CXX} ${CXXFLAGS} -c donut.cpp
clean:
	-rm -f *.gch *.o a.out jade 
