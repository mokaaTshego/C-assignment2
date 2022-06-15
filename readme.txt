Dear Kind Marker,

The submission contain three files

header file : Framesequence.h
source file : Framesequence.cpp
driver file : extractor.cpp

To run the project

 1. use 'make' to compile and link
 2. ./extractor <inputPGMfile> [options]
 
  <inputPGMfile> : image file
 
 options :
 	-t <int> <int> <int> <int> # x1 y1 x2 y2 (begin & end     			origin pixel coords, for frame trajectory)
	-s <int> <int> # <width> <height> (size of small frame in 			pixels)
	-w <string> <string> # write frames with <operation> <name>
