CC = gcc
CFLAGS = -Wall -Wextra -I./include
OBJ_DIR = build

# Targets to build
TARGET1 = exercise_1e.out
TARGET2 = exercise_2.out

# Object files for each target
OBJ1 = $(OBJ_DIR)/exercise_1e/exercise_1e.o $(OBJ_DIR)/cartesian_tree/cartesian_tree.o
OBJ2 = $(OBJ_DIR)/exercise_2/exercise_2.o $(OBJ_DIR)/cartesian_tree/cartesian_tree.o

# Default target
all: directories $(TARGET1) $(TARGET2)

# Rule to compile exercise_1e
$(TARGET1): $(OBJ1)
	$(CC) -o $@ $^

# Rule to compile exercise_2
$(TARGET2): $(OBJ2)
	$(CC) -o $@ $^

# Compile exercise_1e.o
$(OBJ_DIR)/exercise_1e/exercise_1e.o: src/exercise_1e.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile exercise_2.o
$(OBJ_DIR)/exercise_2/exercise_2.o: src/exercise_2.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile cartesian_tree.o
$(OBJ_DIR)/cartesian_tree/cartesian_tree.o: src/cartesian_tree.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create required directories
directories:
	mkdir -p $(OBJ_DIR)/exercise_1e
	mkdir -p $(OBJ_DIR)/exercise_2
	mkdir -p $(OBJ_DIR)/cartesian_tree

# Clean up
clean:
	rm -rf $(OBJ_DIR)/* $(TARGET1) $(TARGET2)