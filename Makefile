CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
default: main

all: main

debug: CXXFLAGS += -g
debug: default

main: main.o mainwin.o store.o product.o donut.o java.o *.h
	${CXX} ${CXXFLAGS} -o main main.o mainwin.o store.o product.o donut.o java.o $(GTKFLAGS)
main.o: main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp $(GTKFLAGS)
mainwin.o: mainwin.cpp *.h
	${CXX} ${CXXFLAGS} -c mainwin.cpp $(GTKFLAGS)
store.o: store.cpp *.h
	${CXX} ${CXXFLAGS} -c store.cpp $(GTKFLAGS)
product.o: product.cpp *.h
	${CXX} ${CXXFLAGS} -c product.cpp
donut.o: donut.cpp *.h
	${CXX} ${CXXFLAGS} -c donut.cpp
java.o: java.cpp *.h
	${CXX} ${CXXFLAGS} -c java.cpp

clean:
	-rm -f *.gch *.o main 
