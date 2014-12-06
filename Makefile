# Thanks to Jun Maillard

CC=gcc

WARNINGS=-W -Wall -Wextra -Werror
#OTHER_FLAGS=-std=c99 -I. -g
OTHER_FLAGS=-std=c11 -I. -g
FLAGS= $(OTHER_FLAGS) $(WARNINGS)

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
$(BUILD_DIR)/%.o: %.c $(BUILD_DIR)
	$(CC) $(FLAGS) $(COMPILE) $< $(OUTPUT) $@

$(BUILD_TEST_DIR)/%.o: $(TEST_DIR)/%.c $(BUILD_TEST_DIR)
	$(CC) $(FLAGS) $(COMPILE) $< $(OUTPUT) $@

clean:
	rm -rf $(BUILD_DIR)
	rm -f *.test
