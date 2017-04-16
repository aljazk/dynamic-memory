TARGET=release/main
CFLAGS=-Wall -Wextra -O3 -flto
LFLAGS=-static -O3 -flto

FILES=$(wildcard src/*.cpp) $(wildcard src/*.c)
FILES+=$(wildcard src/*/*.cpp) $(wildcard src/*/*.c)
FILES+=$(wildcard src/*/*/*.cpp) $(wildcard src/*/*/*.c)
FILES+=$(wildcard src/*/*/*/*.cpp) $(wildcard src/*/*/*/*.c)
FILES+=$(wildcard src/*/*/*/*/*.cpp) $(wildcard src/*/*/*/*/*.c)

OBJS=$(patsubst %,build/%.o,$(basename $(FILES:src/%=%)))
.PHONY: all clean
all: $(TARGET)
$(TARGET): $(OBJS)
	@echo "Linking..."
	@mkdir -p $(@D)
	@g++ $(OBJS) $(LFLAGS) -o $(TARGET)
	@echo "Done."
build/%.o: src/%.cpp
	@echo "Compiling $<"
	@mkdir -p $(@D)
	@g++ -c $< $(CFLAGS) -o $@
build/%.o: src/%.c
	@echo "Compiling $<"
	@mkdir -p $(@D)
	@g++ -c $< $(CFLAGS) -o $@
src/%.cpp : src/%.hpp
src/%.c : src/%.h
clean:
	@rm -rf *.o $(TARGET) $(TARGET).exe build/
	@echo "Cleaned."
