CXX = g++

TARGET1 = DS091
TARGET2 = DS092
TARGET3 = DS093

SRC1 = DS091.cpp
SRC2 = DS092.cpp
SRC3 = DS093.cpp

all: $(TARGET1) $(TARGET2) $(TARGET3)

$(TARGET1): $(SRC1)
	$(CXX) -std=c++11 -o $(TARGET1) $(SRC1)

$(TARGET2): $(SRC2)
	$(CXX) -std=c++11 -o $(TARGET2) $(SRC2)

$(TARGET3): $(SRC3)
	$(CXX) -std=c++11 -o $(TARGET3) $(SRC3)

clean:
	rm -f $(TARGET1) $(TARGET2) $(TARGET3)

.PHONY: all clean