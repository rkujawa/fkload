NATIVE_CC=cc

MAKEROM=makerom
MAKEROM_OBJS=makerom.o

all: $(MAKEROM)

$(MAKEROM) : makerom.o
	$(NATIVE_CC) -o $(MAKEROM) $(MAKEROM_OBJS)	

%.o : %.c
	$(NATIVE_CC) -c $<

clean :
	rm -f $(MAKEROM) $(MAKEROM_OBJS)
