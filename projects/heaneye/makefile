
runTest: 
	gcc -o testme testme.c -fprofile-arcs -ftest-coverage
	.\testme 
	gcov -b testme.c