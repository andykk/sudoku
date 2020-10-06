all:
	gcc -o sudoku sudoku.cpp

tests:
	./sudoku <p1.txt
	./sudoku <p2.txt

