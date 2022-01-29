CXX := g++
CXXFLAGS := -Wall -std=c++17

SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

TEST_DIR := tests

main: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) main $(TEST_DIR)/main

init_test:
	cp main $(TEST_DIR)/main

test:
	cd $(TEST_DIR) && pwd && bash test.sh

lint:
	find src/ -iname *.c -o -iname *.cpp -o -iname *.h | xargs clang-format --dry-run --Werror -style=file
