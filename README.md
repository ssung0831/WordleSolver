Homework 5

Part 4. Wordle

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