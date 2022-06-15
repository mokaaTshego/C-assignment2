# This is a Makefile comment
CC=g++
# the compiler

LIBS=-lm -lX
# the libraries we will ref

extractor.exe: extractor.o FrameSequence.o
	g++ extractor.o FrameSequence.o -o extractor -std=c++2a

extractor.o: extractor.cpp
	g++ -c extractor.cpp -o extractor.o -std=c++2a

FrameSequence.o: FrameSequence.cpp FrameSequence.h
	g++ -c FrameSequence.cpp -o FrameSequence.o -std=c++2a


run:
	./extractor

clean:
	@rm -f *.o
	@rm driver.exe