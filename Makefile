CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o my_string.o generic_vector.o tree.o

ALL: string_driver unit_test
string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c my_string.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
generic_vector.o: generic_vector.c generic_vector.h
	$(CC) $(CFLAGS) -c  generic_vector.c -o generic_vector.o
tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c -o tree.o
unit_test.o: unit_test.c unit_test.h
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
test_def.o: test_def.c
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o
unit_test: my_string.o unit_test.o test_def.o
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_def.o my_string.o
clean:
	rm string_driver unit_test $(OBJECTS)
