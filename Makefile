CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

dbfs: dbfs.c 
	$(CC) dbfs.c -o dbfs $(CFLAGS)