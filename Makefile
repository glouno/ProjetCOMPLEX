# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I./include
OBJ_DIR = build
SRC_DIR = src

# Automatically find all exercise source files
SOURCES = $(wildcard $(SRC_DIR)/exercise_*.c)

# Generate object files for all source files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Generate executable names by replacing .c with .out
EXECUTABLES = $(SOURCES:$(SRC_DIR)/%.c=%.out)

# Default target to build all executables
all: directories $(EXECUTABLES)

# Rule to build each executable
%.out: $(OBJ_DIR)/%.o $(OBJ_DIR)/cartesian_tree/cartesian_tree.o
	$(CC) -o $@ $^

# Rule to compile .o files for each source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile shared cartesian_tree.o
$(OBJ_DIR)/cartesian_tree/cartesian_tree.o: $(SRC_DIR)/cartesian_tree.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create required directories
directories:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/cartesian_tree
	mkdir -p $(OBJ_DIR)/exercise_1e
	mkdir -p $(OBJ_DIR)/exercise_2
	mkdir -p $(OBJ_DIR)/exercise_3

# Clean up
clean:
	rm -rf $(OBJ_DIR)/* *.out