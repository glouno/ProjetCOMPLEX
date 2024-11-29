# flags
CFLAGS = -Iinclude -Wall -Wextra -g

# object files for each compilation target
OBJ_1 = build/ct.o build/ex1.o
OBJ_2 = build/ct.o build/top.o build/ex2.o
OBJ_3 = build/ct.o build/top.o build/ex3.o
OBJ_4 = build/ct.o build/top.o build/ex4.o
OBJ_5 = build/ct.o build/top.o build/ex5.o

# target executables
TARGET_1 = bin/ex1
TARGET_2 = bin/ex2
TARGET_3 = bin/ex3
TARGET_4 = bin/ex4
TARGET_5 = bin/ex5

# rules
all: setup $(TARGET_1) $(TARGET_2) $(TARGET_3) $(TARGET_4) $(TARGET_5)

setup:
	mkdir -p bin build data

# rules for implementation files
build/ct.o: src/cartesian_tree.c include/cartesian_tree.h
	gcc $(CFLAGS) -c src/cartesian_tree.c -o build/ct.o

build/top.o: src/tree_operations.c include/cartesian_tree.h include/tree_operations.h
	gcc $(CFLAGS) -c src/tree_operations.c -o build/top.o

# rules for exercise 1
$(TARGET_1): $(OBJ_1)
	gcc $(OBJ_1) -o $(TARGET_1)

build/ex1.o: src/exercise_1.c include/cartesian_tree.h
	gcc $(CFLAGS) -c src/exercise_1.c -o build/ex1.o

# rules for exercise 2
$(TARGET_2): $(OBJ_2)
	gcc $(OBJ_2) -o $(TARGET_2)

build/ex2.o: src/exercise_2.c include/cartesian_tree.h include/tree_operations.h
	gcc $(CFLAGS) -c src/exercise_2.c -o build/ex2.o

# rules for exercise 3
$(TARGET_3): $(OBJ_3)
	gcc $(OBJ_3) -o $(TARGET_3)

build/ex3.o: src/exercise_3.c include/cartesian_tree.h include/tree_operations.h
	gcc $(CFLAGS) -c src/exercise_3.c -o build/ex3.o

# rules for exercise 4
$(TARGET_4): $(OBJ_4)
	gcc $(OBJ_4) -o $(TARGET_4)

build/ex4.o: src/exercise_4.c include/cartesian_tree.h include/tree_operations.h
	gcc $(CFLAGS) -c src/exercise_4.c -o build/ex4.o

# rules for exercise 5
$(TARGET_5): $(OBJ_5)
	gcc $(OBJ_5) -o $(TARGET_5)

build/ex5.o: src/exercise_5.c include/cartesian_tree.h include/tree_operations.h
	gcc $(CFLAGS) -c src/exercise_5.c -o build/ex5.o

clean:
	rm -rf bin build