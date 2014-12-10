CXX = g++
CFLAGS = -c -Wall
LDFLAGS=
SOURCES = main.cpp balancedTree.cpp dictionary.cpp stopwatch.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf *o main
