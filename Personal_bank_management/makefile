output: main.o account.o
	clang++ -v main.o account.o -o output
main.o: main.cpp account.h
	clang++ -v -c main.cpp -o main.o
account.o: account.cpp account.h
	clang++ -v -c account.cpp -o account.o

