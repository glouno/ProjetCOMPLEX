# Project structure
The project is organized into 3 main directories: docs, include, src.

Docs includes the solutions for the theoretical exercises in the project.

Src includes all the code of the project. We have split things into 2 utility files ('cartesian_tree.c' and 'tree_operations.c); these two files implement all the operations on trees. The rest of the files in src implement the required tasks for each exercise, i.e. they are for testing.

Include contains header files for the utility files from src.

# How to build the project
Make accepts as a target "setup" which creates the directories in which executables, objects and performance data will be built.

After running setup, running make with an exercise name will build that specific exercise.

Example usage: $ make bin/ex1

Otherwise, everything can be built directly by running make with no parameters.

# Plotting performance for exercise 5
The directory '/plot' contains Python functions for plotting the performance of our implementations. These functions are named after the tree operations they analyze.

Any of these files can be run with a Python interpreter.

Required packages are: numpy, matplotlib.pyplot, pandas.

(Did not include package versions, but they are standard, so latest version should be good?)
