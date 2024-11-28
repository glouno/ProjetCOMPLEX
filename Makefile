# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I./include
OBJ_DIR = build
SRC_DIR = src
BIN_DIR = bin

# Automatically find all exercise source files
SOURCES = $(wildcard $(SRC_DIR)/exercise_*.c)

# Generate object files for all source files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Generate executable names in the bin/ directory
EXECUTABLES = $(SOURCES:$(SRC_DIR)/%.c=$(BIN_DIR)/%.out)

# Default target to build all executables
all: directories $(BIN_DIR) $(EXECUTABLES)

# Rule to build each executable
$(BIN_DIR)/%.out: $(OBJ_DIR)/%.o $(OBJ_DIR)/cartesian_tree/cartesian_tree.o
	mkdir -p $(dir $@)  # Ensure bin directory exists
	$(CC) -o $@ $^

# Rule to compile .o files for each source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)  # Ensure object directory exists
	$(CC) $(CFLAGS) -c $< -o $@

# Compile shared cartesian_tree.o
$(OBJ_DIR)/cartesian_tree/cartesian_tree.o: $(SRC_DIR)/cartesian_tree.c
	mkdir -p $(dir $@)  # Ensure object directory exists
	$(CC) $(CFLAGS) -c $< -o $@

# Create required directories
directories:
	mkdir -p $(OBJ_DIR)

# Ensure bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)