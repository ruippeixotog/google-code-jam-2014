QUAL_CC_FILES = $(wildcard qualification/*.cpp)
QUAL_BIN_FILES = $(patsubst qualification/%.cpp, %, $(QUAL_CC_FILES))

BIN_FILES = $(QUAL_BIN_FILES)
CC_FLAGS = -Wall -O2 -lm
CC = g++

all: $(BIN_FILES)

.PHONY: check-syntax
check-syntax:
	$(CC) $(CC_FLAGS) -Wextra -pedantic -fsyntax-only $(CHK_SOURCES)

$(QUAL_BIN_FILES):%: qualification/%.cpp
	$(CC) $(CC_FLAGS) -o $@ $<

clean:
	rm -f $(BIN_FILES)
