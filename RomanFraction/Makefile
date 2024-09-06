all: RomanFraction.build

RomanFraction.build:
	g++ main.cpp RomanFraction.h RomanFraction.cpp -o RomanFraction.build

test: RomanFraction.build
	bash ../test.sh RomanFraction test.1 result.1

clean:
	rm RomanFraction.build


