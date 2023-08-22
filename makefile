CXX = g++ -std=c++11
CXXFLAGS = -I/opt/homebrew/Cellar/sfml/2.6.0/include
LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.6.0/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

TreeGenerator: main.o Pixel.o TrunkPixel.o lodepng.o Trunk.o LeafPixel.o

	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ $(LIBS) 


%.o: %.cpp

	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $< -o $@ $(LIBS) 

clean:

	rm *.o TreeGenerator