# Makefile

CC = g++
CFLAGS = -Wall

DEPS = estadual.h nacional.h dependencias.h
OBJ = main.o estadual.o nacional.o
EXECS = covidData

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

covidData: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	make clean

.PHONY: clean cleanExecs cleanAll

clean:
	rm -rf *.o

cleanExecs:
	rm -rf $(EXECS)

cleanAll: clean cleanExecs
