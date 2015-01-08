# Thanks to Jun Maillard

CC=gcc

WARNINGS=-W -Wall -Wextra -Werror
OTHER_FLAGS=-std=c99 -I. -g
#OTHER_FLAGS=-std=c11 -I. -g
FLAGS= $(OTHER_FLAGS) $(WARNINGS)

COMPILE=-c
OUTPUT=-o
LINK_FLAGS=-lm

BUILD_DIR=_build
EXEC_DIR=exec
BUILD_EXEC_DIR=$(BUILD_DIR)/$(EXEC_DIR)

SOURCES=${wildcard *.c}
OBJECTS=$(patsubst %.c,_build/%.o,$(SOURCES))
EXEC_SOURCES=$(wildcard $(EXEC_DIR)/*.c)
EXEC=$(patsubst $(EXEC_DIR)/%.c,%.bin,$(EXEC_SOURCES))

all: $(OBJECTS) exec

exec: $(BUILD_EXEC_DIR) $(EXEC)

%.bin: $(OBJECTS) $(BUILD_EXEC_DIR)/%.o
	$(CC) $(FLAGS) $^ $(LINK_FLAGS) $(OUTPUT) $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_EXEC_DIR): $(BUILD_DIR)
	mkdir -p $(BUILD_EXEC_DIR)

$(BUILD_DIR)/%.o: %.c %.h $(BUILD_DIR)
	$(CC) $(FLAGS) $(COMPILE) $< $(OUTPUT) $@

$(BUILD_EXEC_DIR)/%.o: $(EXEC_DIR)/%.c $(BUILD_EXEC_DIR)
	$(CC) $(FLAGS) $(COMPILE) $< $(OUTPUT) $@

clean:
	rm -rf $(BUILD_DIR)
	rm -f *.bin
