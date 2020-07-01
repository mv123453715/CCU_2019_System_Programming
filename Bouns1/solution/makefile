#³¢®Ë¸Û ¸ê¤u¤T 406410114
TARGET=a.out

$(TARGET): counting_file_types.o error.o pathalloc.o
	$(CC) -o $@ $^ 

counting_file_types.o: counting_file_types.c
error.o: error.c
pathalloc.o:pathalloc.c

clean:
	rm -f counting_file_types.o error.o pathalloc.o $(TARGET)