 CXX = g++
 CXXFLAGS = -std=c++2a -Wall -c 
 LXXFLAGS = -std=c++2a
 OBJECTS = main.o cell.o maze.o
 TARGET = main


 $(TARGET) : $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o : main.cpp	cell.o maze.o
	$(CXX) $(CXXFLAGS) main.cpp
cell.o : cell.cpp
	$(CXX) $(CXXFLAGS) cell.cpp
maze.o : maze.cpp
	$(CXX) $(CXXFLAGS) maze.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
	