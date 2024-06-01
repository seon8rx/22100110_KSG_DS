CXX = g++
CXXFLAGS = -I./lib
LDFLAGS = -L./lib
LIBS = -lSorting

ifeq ($(DEBUG), 1)
    CXXFLAGS += -DDEBUG
endif

EXECUTABLES = DS071 DS072 DS073 DS074 DS075 DS076

LIB_OBJECT = lib/sorting.o
LIBRARY = lib/libSorting.a

all: $(EXECUTABLES)

DS071: DS071.cpp
	$(CXX) -o DS071 DS071.cpp $(CXXFLAGS)
DS072: DS072.cpp
	$(CXX) -o DS072 DS072.cpp $(CXXFLAGS)
DS073: DS073.cpp
	$(CXX) -o DS073 DS073.cpp $(CXXFLAGS)
DS074: DS074.cpp
	$(CXX) -o DS074 DS074.cpp $(CXXFLAGS)
DS075: DS075.cpp
	$(CXX) -o DS075 DS075.cpp $(CXXFLAGS)
DS076: DS076.cpp $(LIBRARY)
	$(CXX) -o DS076 DS076.cpp $(CXXFLAGS) $(LDFLAGS) $(LIBS)

$(LIBRARY): $(LIB_OBJECT)
	ar rcs $(LIBRARY) $(LIB_OBJECT)

lib/sorting.o: lib/sorting.cpp lib/Sorting.h
	$(CXX) -c lib/sorting.cpp -o lib/sorting.o $(CXXFLAGS)

clean:
	rm -f $(EXECUTABLES) $(LIB_OBJECT) $(LIBRARY)

.PHONY: all clean DS071 DS072 DS073 DS074 DS075 DS076
