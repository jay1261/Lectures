.SUFFIXES = .c .o
OBJECT = ascii.o main.o expo.o convert.o sum.o
SRC = main.c ascii.c expo.c convert.c sum.c
CC = gcc
CFLAGS = -g -c
TARGET = convert
$(TARGET) : $(OBJECT)
	$(CC) -o $(TARGET) $(OBJECT) -lm

clean: 
	rm -rf $(OBJECT)

main.o: main.c
ascii.o: ascii.c
convert.o: convert.c
expo.o: expo.c
sum.o: sum.c


