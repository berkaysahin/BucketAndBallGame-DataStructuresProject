all: compile run

compile:
	g++ -I./include -c ./src/Bucket.cpp -o ./lib/Bucket.o
	g++ -I./include -c ./src/Ball.cpp -o ./lib/Ball.o
	g++ -I./include -c ./src/BucketControl.cpp -o ./lib/BucketControl.o
	g++ -I./include -c ./src/Main.cpp -o ./lib/Main.o
	g++ -I ./include -o ./bin/Test ./lib/Main.o ./lib/BucketControl.o ./lib/Bucket.o ./lib/Ball.o

run:
	./bin/Test.exe