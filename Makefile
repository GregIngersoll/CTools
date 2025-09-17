CC = gcc

BINARIES = hello
SOURCES = hello.c
OBJECTS = hello.o

all: hello

hello: $(OBJECTS)

$(OBJECTS):$(SOURCES)

clean:
	rm $(BINARIES) $(OBJECTS)
