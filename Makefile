CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -rdynamic $(shell pkg-config --cflags gtk+-3.0)
LIBS = $(shell pkg-config --libs gtk+-3.0)
TARGET = magic_square
SOURCES = proyecto1.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean install run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LIBS)

%.o: %.c proyecto1.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

install:
	sudo apt update
	sudo apt install -y libgtk-3-dev glade

run: $(TARGET)
	./$(TARGET)

debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)
