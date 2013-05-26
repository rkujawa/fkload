NATIVE_CC=cc

MAKEROM=makerom
MAKEROM_OBJS=makerom.o sum.o

all: $(MAKEROM)

$(MAKEROM) : $(MAKEROM_OBJS)
	$(NATIVE_CC) -o $(MAKEROM) $(MAKEROM_OBJS)	

%.o : %.c
	$(NATIVE_CC) -c $<

clean :
	rm -f $(MAKEROM) $(MAKEROM_OBJS)
