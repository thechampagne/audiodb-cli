CXX := g++
CFLAGS := -Wall -Wextra -pthread

.PHONY: all
all: src/main.cpp
	$(CXX) $(CFLAGS) $< -o bin/audiodb -l:audiodb.a

test:
	bin/audiodb --artist-id 111674

clean:
	find bin/ -type f \( -name '*.exe' \) -delete