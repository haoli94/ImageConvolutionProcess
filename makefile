CXX := g++
CXXFLAGS := -O3 -std=c++11 -Wall -Wconversion -Wextra -pedantic 
main: main.cpp image.cpp image.hpp process.cpp process.hpp
	$(CXX) $(CXXFLAGS) -o main main.cpp image.cpp process.cpp -ljpeg  
$.PHONY: clean
clean:
	$(RM) main
