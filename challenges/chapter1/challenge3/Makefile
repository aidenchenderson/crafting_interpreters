# useful reference for when i forgor: https://www.cs.usask.ca/staff/oster/makefiles.html

CC = gcc
CFLAGS = -g -Wall

# for real projects put the object files and executable into a build directory
# for this basic exercise the outputs are stored in the "root" at challenge3/
TARGET = dll_prog.out
# BIN_DIR = bin 

OBJS = doubly_linked_list.o main.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJS)

doubly_linked_list.o: doubly_linked_list.c doubly_linked_list.h
	$(CC) $(CFLAGS) -c doubly_linked_list.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm $(OBJS) $(TARGET)