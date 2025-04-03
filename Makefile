# Makefile

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = matrix_app
SRC = main.cpp matrix.cpp
HDR = matrix.hpp

all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
