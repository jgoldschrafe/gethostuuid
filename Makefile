CC=gcc

build: src/gethostuuid.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o bin/gethostuuid src/gethostuuid.c

clean:
	rm -f bin/gethostuuid
