CXX := g++
CXXFLAGS := -std=c++17
SRC := src/HVLCS.cpp
BIN := hvlcs

.PHONY: all clean run

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(BIN)
	rm -f output/out.txt output/.tmp_out