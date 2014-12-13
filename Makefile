# Thanks to Jun Maillard

CC=gcc

WARNINGS=-W -Wall -Wextra -Werror
MOREWARNINGS=$(WARNINGS) -Wcast-qual -Wcast-align -Wfloat-equal -Wshadow -Wpointer-arith -Wunreachable-code -Wchar-subscripts -Wcomment -Wformat -Werror-implicit-function-declaration -Wmain -Wmissing-braces -Wparentheses -Wsequence-point -Wreturn-type -Wswitch -Wuninitialized -Wreorder -Wundef -Wwrite-strings -Wsign-compare -Wmissing-declarations -pedantic -Wconversion -Wmissing-noreturn -Wold-style-cast -Wunused -Wsign-conversion -Wunused -Wstrict-aliasing -Wstrict-overflow -Wconversion -Wdisabled-optimization

OTHER_FLAGS=-std=c99 -I. -g
#OTHER_FLAGS=-std=c11 -I. -g
FLAGS= $(OTHER_FLAGS) $(MOREWARNINGS)

COMPILE=-c
OUTPUT=-o
LINK_FLAGS=-lm

BUILD_DIR=_build
TEST_DIR=tests
BUILD_TEST_DIR=$(BUILD_DIR)/$(TEST_DIR)

SOURCES=${wildcard *.c}
OBJECTS=$(patsubst %.c,_build/%.o,$(SOURCES))
TESTS_SOURCES=$(wildcard $(TEST_DIR)/*.c)
TESTS=$(patsubst $(TEST_DIR)/%.c,%.test,$(TESTS_SOURCES))

all: $(OBJECTS)

tests: $(BUILD_TEST_DIR) $(TESTS)

%.test: $(OBJECTS) $(BUILD_TEST_DIR)/%.o
	$(CC) $(FLAGS) $(LINK_FLAGS) $^ $(OUTPUT) $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_TEST_DIR): $(BUILD_DIR)
	mkdir -p $(BUILD_TEST_DIR)

# TODO : what about the .h ?
$(BUILD_DIR)/%.o: %.c %.h $(BUILD_DIR)
	$(CC) $(FLAGS) $(COMPILE) $< $(OUTPUT) $@

$(BUILD_TEST_DIR)/%.o: $(TEST_DIR)/%.c $(BUILD_TEST_DIR)
	$(CC) $(FLAGS) $(COMPILE) $< $(OUTPUT) $@

clean:
	rm -rf $(BUILD_DIR)
	rm -f *.test
