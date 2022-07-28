output: main.o Account.o Date.o 
	clang++ -v main.o account.o Date.o -o output
main.o: main.cpp Account.h
	clang++ -v -c main.cpp -o main.o
Account.o: Account.cpp Account.h
	clang++ -v -c Account.cpp -o Account.o
Date.o: Date.cpp Date.h
	clang++ -v -c Date.cpp -o Date.o