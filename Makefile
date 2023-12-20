compiler = g++
flags = -g -Wall -std=c++17
compile = $(compiler) $(flags)

main: main.cpp
	$(compile) main.cpp -o main

.PHONY: clean
clean:
	rm -rf *.o main