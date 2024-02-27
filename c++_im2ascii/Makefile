OPENCV = `pkg-config opencv4 --cflags --libs`
LIBS = $(OPENCV)

all: image2ascii_cpp

image2ascii_cpp: im2ascii.cpp
	g++ im2ascii.cpp -o im2ascii_cpp $(LIBS)