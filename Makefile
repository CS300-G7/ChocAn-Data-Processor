CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic
TARGET = dataproc
INCLUDE = -I 
SRC = 

datatest: data.o data_test.o
	${CXX} -o datatest data.o data_test.o

data.o: data.cpp data.h
	${CXX} ${CXXFLAGS} -c data.cpp

data_test.o: data_test.cpp
	${CXX} ${CXXFLAGS} -c data_test.cpp	

clean:
	rm *.o
