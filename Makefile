CXX := g++
CXXFLAGS := -Wall -static -static-libgcc -static-libstdc++ -std=c++17

# For compiling
SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SRC_FILES))
EXECUTABLE_NAME := main

# For testing
TEST_DIR := tests
TEST_DRIVER := test.pl
TEST_DRIVER_ENGINE := perl
TEST_PAYLOAD := cd $(TEST_DIR) && pwd && $(TEST_DRIVER_ENGINE) $(TEST_DRIVER)

# For linting and format
LINT_PAYLOAD := find src/ -iname *.c -o -iname *.cc -o -iname *.h | xargs clang-format --dry-run --Werror -style=file
FORMAT_PAYLOAD := find src/ -iname *.c -o -iname *.cc -o -iname *.h | xargs clang-format -i -style=file

# For coverage
COVERAGE_FILENAME := coverage.info
COVERAGE_OUTPUT_DIR := coverage
COVERAGE_INIT_PAYLOAD := lcov --capture --directory obj --output-file=$(COVERAGE_FILENAME)
COVERAGE_EXTRACT_PAYLOAD := lcov --extract $(COVERAGE_FILENAME) '*.cc' -o $(COVERAGE_FILENAME)
COVERAGE_GENERATE_REPORT_PAYLOAD := genhtml $(COVERAGE_FILENAME) --output-directory=$(COVERAGE_OUTPUT_DIR)

# For cleaning
REMOVAL := $(OBJ_DIR)/ $(EXECUTABLE_NAME) $(TEST_DIR)/$(EXECUTABLE_NAME) $(COVERAGE_FILENAME) $(COVERAGE_OUTPUT_DIR)/
JUNK_HUNTER := jh.pl
JUNK_HUNTER_ENGINE := perl

# Link object files to execution
$(EXECUTABLE_NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	@ mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean directory for GitHub pushes
clean:
	rm -rf $(REMOVAL)

# Initialise files for testing
init_test:
	cp $(EXECUTABLE_NAME) $(TEST_DIR)/$(EXECUTABLE_NAME)

# Testing code
test:
	$(TEST_PAYLOAD)

# Testing code on workflow
test_silent: TEST_PAYLOAD += --silent
test_silent:
	$(TEST_PAYLOAD)

# Hunting for junks
junk_hunt:
	$(JUNK_HUNTER_ENGINE) $(JUNK_HUNTER) $(REMOVAL)

# Lint for code format
lint:
	$(LINT_PAYLOAD)

# Format code
format:
	$(FORMAT_PAYLOAD)

# Run test coverage
gcov: CXXFLAGS += --coverage
gcov: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE_NAME) $^

# Generate human-readable coverage.
lcov:
	$(COVERAGE_INIT_PAYLOAD) && $(COVERAGE_EXTRACT_PAYLOAD)

# Generate test coverage report
generate-coverage-report:
	$(COVERAGE_GENERATE_REPORT_PAYLOAD)
