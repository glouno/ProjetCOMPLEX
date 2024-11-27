CC = gcc
CFLAGS = -Wall -Wextra -I./include
OBJ_DIR = build

# targets to build
TARGET1 = exercise_1e

# object files for each target
OBJ1 = $(OBJ_DIR)/exercise_1e/exercise_1e.o $(OBJ_DIR)/cartesian_tree/cartesian_tree.o

# default target
all: $(TARGET1)

# rule to compile exercise_1e
$(TARGET1): $(OBJ1)
	$(CC) -o $@ $^

# compile cartesian_tree.o
$(OBJ_DIR)/cartesian_tree/cartesian_tree.o: src/cartesian_tree.c
	$(CC) $(CFLAGS) -c $< -o $@

# compile exercise_1e.o
$(OBJ_DIR)/exercise_1e/exercise_1e.o: src/exercise_1e.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean up
clean:
	rm -rf $(OBJ_DIR)/* $(TARGET1)