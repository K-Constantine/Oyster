all: oyster

CXX=g++

SRCS=$(wildcard src/*.cpp src/model/*.cpp src/repository/*.cpp src/service/*.cpp test/*.cpp)
OBJS=$(subst %.cpp, %.o,$(SRCS))

clean:
	rm -rf oyster

test: clean $(OBJS) 
		$(CXX) -o oyster $(OBJS) -std=c++11 && ./oyster test

oyster: clean $(OBJS) 
		$(CXX) -o oyster $(OBJS) -std=c++11 && ./oyster
