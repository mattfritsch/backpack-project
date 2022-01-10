BDIR = bin
IDIR = include
ODIR = obj
SDIR = src

CC = gcc
CFLAGS= -Wall -I$(IDIR)

_PROG = backpack.bin
PROG = $(patsubst %,$(BDIR)/%,$(_PROG))

_DEP = bag.h dp_array.h dp_list.h elmlist.h global.h list.h objects.h prec.h space_array.h states.h outils.h
DEP = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o dp_array.o space_array_1.o space_array_2.o space_array_3.o space_array_4.o space_array_5.o space_array.o objects.o objects_2.o list.o elmlist.o dp_rec.o dp_rec2.o outils.o dp_list.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: run dirs clean delete

run: dirs $(PROG)
	./$(PROG)

dirs:
	@mkdir -p $(ODIR)
	@mkdir -p $(BDIR)
    
$(PROG) : $(OBJ)
	$(CC) $(LFLAGS) $(CFLAGS) -o $@ $^

$(ODIR)/%.o: $(SDIR)/%.c $(DEP)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(ODIR)

delete: clean
	rm -rf $(BDIR) $(ODIR)