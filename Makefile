######################################################################
# COSC1283/1284 - Programming Techniques
# Semester 1 2013 Assignment #1
# Full Name        : Joshua Yu
# Student Number   : 323 5184
# Yallara Username : s3235184
# Course Code      : COSC1284
# Program Code     : BP162
# Start up code provided by Paul Miller and Xiaodong Li
######################################################################
CC = gcc
CFLAGS = -Wall -ansi -pedantic $(DEBUG)
OBJS = assign1.o options1.o utility1.o

compile: 
	$(CC) $(CFLAGS) assign1.c options1.c utility1.c -o assign1
	
	
clean: 
	rm -f *.o core assign1


archive:
	zip $(USER)-a1.zip assign1.c assign1.h options1.c utility1.c Makefile \
	readme1.txt
