CC = gcc
CFLAGS = -Wall -Wextra -O2 -I"C:/msys64/mingw64/include" -I"./include/"
LDFLAGS = C:/msys64/mingw64/lib/pdcurses.a

SOURCES := $(wildcard ./src/*.c)
OBJECTS := $(patsubst ./src/%.c, ./src/%.o, $(SOURCES))
TARGET = OshiReview

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

./src/%.o: ./src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	cmd /C "del /Q $(subst /,\,$(OBJECTS)) $(TARGET).exe"
