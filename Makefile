CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic
TARGET = dataproc
INCLUDE = -I 
SRC = 

all:
	${CXX} ${CXXFLAGS} ${INCLUDE} -o ${TARGET};

# Eventually all tests should be in their own directory.
test:
	${CXX} ${CXXFLAGS} -I ./tests tests/*.cpp -o tests/test;

