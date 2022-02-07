CXX := g++
CXXFLAGS := -Wall -static -static-libgcc -static-libstdc++ -std=c++17

SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

TEST_DIR := tests

# Link object files to execution
main: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean directory for GitHub pushes
clean:
	rm -rf $(OBJ_DIR) main $(TEST_DIR)/main
	rm -rf *.gcov coverage.info coverage/

# Initialise files for testing
init_test:
	cp main $(TEST_DIR)/main

# Testing code
test:
	cd $(TEST_DIR) && pwd && bash test.sh

# Lint for code format
lint:
	find src/ -iname *.c -o -iname *.cpp -o -iname *.h | xargs clang-format --dry-run --Werror -style=file

# Format code
format:
	find src/ -iname *.c -o -iname *.cpp -o -iname *.h | xargs clang-format -i -style=file

# Run test coverage
gcov: CXXFLAGS += --coverage
gcov: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o main $^

# Generate human-readable coverage.
lcov:
	lcov --capture --directory obj --output-file=coverage.info
	lcov --extract coverage.info '*.cpp' -o coverage.info

# Generate test coverage report
generate-coverage-report:
	genhtml coverage.info --output-directory=coverage
