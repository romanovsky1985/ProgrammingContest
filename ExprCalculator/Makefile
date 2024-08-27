all: ExprCalculator.build

ExprCalculator.build:
	g++ main.cpp ExprCalculator.h ExprCalculator.cpp -o ExprCalculator.build

test: ExprCalculator.build
	bash ../test.sh ExprCalculator test.1 result.1

clean:
	rm ExprCalculator.build


