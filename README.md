Homework 5

Wordle

This is my program to output all of the possible words that this wordle could be,
using the green and yellow letters

To run basic testing:
cd hw5
make wordle-driver
./wordle-driver -i-- dn

To run in-depth testing:
cd hw5/hw5_tests/wordle_tests
make wordle_tests
./wordle_tests

Valgrind:
valgrind --tool=memcheck --leak-check=yes ./wordle_tests



Schedwork

This is my program to display a schedule of workers given their availability, 
num of workers per day, and max shifts. It uses backtracking.

To run basic testing:
cd hw5
make schedwork-driver
./schedwork-driver

To run in-depth testing:
cd hw5/hw5_tests/schedwork_tests
make schedwork_tests
./schedwork_tests

Valgrind:
valgrind --tool=memcheck --leak-check=yes ./schedwork_tests