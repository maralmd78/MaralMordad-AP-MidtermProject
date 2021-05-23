 CXX = g++
 CXXFLAGS = -std=c++2a -Wall -c 
 LXXFLAGS = -std=c++2a	
 OBJECTS = main.o cell.o maze.o	bfssolver.o
 TARGET = main


 $(TARGET) : $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET) -lncurses
main.o : main.cpp	cell.o	maze.o	bfssolver.o
	$(CXX) $(CXXFLAGS) main.cpp	-lncurses
cell.o : cell.cpp
	$(CXX) $(CXXFLAGS) cell.cpp	-lncurses
maze.o : maze.cpp
	$(CXX) $(CXXFLAGS) maze.cpp	-lncurses
bfssolver.o : bfssolver.cpp
	$(CXX) $(CXXFLAGS) bfssolver.cpp -lncurses
clean:
	rm -f $(TARGET) $(OBJECTS)
	
	