all: HorsesRoute.build

HorsesRoute.build:
	g++ main.cpp HorsesRoute.h HorsesRoute.cpp -o HorsesRoute.build

test: HorsesRoute.build
	bash ../test.sh HorsesRoute test.1 result.1

clean:
	rm HorsesRoute.build


