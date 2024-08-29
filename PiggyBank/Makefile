all: PiggyBank.build

PiggyBank.build:
	g++ main.cpp PiggyBank.h PiggyBank.cpp -o PiggyBank.build

test: PiggyBank.build
	bash ../test.sh PiggyBank test.1 result.1
	bash ../test.sh PiggyBank test.2 result.2

clean:
	rm PiggyBank.build


