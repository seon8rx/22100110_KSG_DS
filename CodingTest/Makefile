CXX = g++
CXXFLAGS = -I./lib
LDFLAGS = -L./lib
LIBS = -lSorting

EXECUTABLES = DS101 DS103

LIB_OBJECT = lib/sorting.o
LIBRARY = lib/libSorting.a

all: $(EXECUTABLES)

DS101: DS101.cpp $(LIBRARY)
	$(CXX) -o DS101 DS101.cpp $(CXXFLAGS) $(LDFLAGS) $(LIBS)
DS103: DS103.cpp $(LIBRARY)
	$(CXX) -o DS103 DS103.cpp $(CXXFLAGS) $(LDFLAGS) $(LIBS)

$(LIBRARY): $(LIB_OBJECT)
	ar rcs $(LIBRARY) $(LIB_OBJECT)

lib/sorting.o: lib/sorting.cpp lib/Sorting.h
	$(CXX) -c lib/sorting.cpp -o lib/sorting.o $(CXXFLAGS)

clean:
	rm -f $(EXECUTABLES) $(LIB_OBJECT) $(LIBRARY)

.PHONY: all clean DS101
