CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

EXECUTABLE = app

# Default target: build the executable
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Rule to compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target: remove object files and the executable
clean:
	rm -f $(OBJS) $(EXECUTABLE)
