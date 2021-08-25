#Makefile

CC =  g++
CFLAGS = -Wall 

OBJDIR = obj
SRCDIR = src
OBJS = $(OBJDIR)/main.o\
		$(OBJDIR)/vertice.o\
		$(OBJDIR)/aresta.o\
		$(OBJDIR)/grafo.o

EXEC = grafo

build: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	    $(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm $(EXEC) $(OBJDIR)/*.o
