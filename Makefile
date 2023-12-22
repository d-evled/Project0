BIN_DIR = exe
flags = -g -Wall -std=c++17
compile = $(compiler) $(flags)

all: $(BIN_DIR)/.dirstamp $(BIN_DIR)/main

$(BIN_DIR)/main: src/main.cpp $(BIN_DIR)/animal.o $(BIN_DIR)/dog.o $(BIN_DIR)/reduceToHeader.o $(BIN_DIR)/generateDot.o
	$(CXX) $(CPPFLAGS) $^ -o $@

$(BIN_DIR)/animal.o: src/animal.cpp lib/animal.h 
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/dog.o: src/dog.cpp lib/dog.h 
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/reduceToHeader.o: src/reduceToHeader.cpp lib/reduceToHeader.h 
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/generateDot.o: src/generateDot.cpp lib/generateDot.h 
	$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp