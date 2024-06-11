CXX = g++
CXXFLAGS = -I./lib
LDFLAGS = -L./lib
LIBS = -lSorting

EXECUTABLES = DS101 DS103 DS104 DS105 DS106 DS107 DS108 DS109 DS110

LIB_OBJECT = lib/sorting.o
LIBRARY = lib/libSorting.a

all: $(EXECUTABLES)

DS101: DS101.cpp $(LIBRARY)
	$(CXX) -o DS101 DS101.cpp $(CXXFLAGS) $(LDFLAGS) $(LIBS)
DS102: DS102.cpp $(LIBRARY)
	$(CXX) -std=c++11 -o DS102 DS102.cpp $(CXXFLAGS) $(LDFLAGS) $(LIBS)
DS103: DS103.cpp $(LIBRARY)
	$(CXX) -o DS103 DS103.cpp $(CXXFLAGS) $(LDFLAGS) $(LIBS)
DS104: DS104.cpp
	$(CXX) -o DS104 DS104.cpp
DS105: DS105.cpp
	$(CXX) -o DS105 DS105.cpp
DS106: DS106.cpp
	$(CXX) -o DS106 DS106.cpp
DS107: DS107.cpp $(LIBRARY)
	$(CXX) -o DS107 DS107.cpp $(CXXFLAGS) $(LDFLAGS) $(LIBS)
DS108: DS108.cpp
	$(CXX) -std=c++11 -o DS108 DS108.cpp
DS109: DS109.cpp
	$(CXX) -std=c++11 -o DS109 DS109.cpp
DS110: DS110.cpp
	$(CXX) -std=c++11 -o DS110 DS110.cpp

$(LIBRARY): $(LIB_OBJECT)
	ar rcs $(LIBRARY) $(LIB_OBJECT)

lib/sorting.o: lib/sorting.cpp lib/Sorting.h
	$(CXX) -c lib/sorting.cpp -o lib/sorting.o $(CXXFLAGS)

clean:
	rm -f $(EXECUTABLES) $(LIB_OBJECT) $(LIBRARY)

.PHONY: all clean DS101 DS102 DS103 DS104 DS105 DS106 DS107 DS108 DS109 DS110
