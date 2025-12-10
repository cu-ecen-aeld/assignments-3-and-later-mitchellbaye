CROSS_COMPILE=

IDIR =../include
CC=$(CROSS_COMPILE)gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = writer.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = writer.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

writer: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean



clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ writer
