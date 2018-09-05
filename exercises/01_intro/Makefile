SRC = $(wildcard *.cc)
EXE = $(SRC:.cc=.x)
CXX = c++
FLAGS = -std=c++11 -Wall -Wextra

all: $(EXE)

%.x: %.cc
	$(CXX) $< -o $@ $(FLAGS) $(INCLUDE)


clean:
	rm -f $(EXE) *~

.PHONY: clean
