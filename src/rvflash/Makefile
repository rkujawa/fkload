CC=vc
RMRF=rm -rf

CFLAGS=
LDFLAGS=-lamiga

OBJECTS=rvflash.o cliparse.o
ADDHEADERS=config.h hardware.h

EXECUTABLE=rvflash

all: $(EXECUTABLE) 

$(EXECUTABLE) : $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(LDFLAGS) $(OBJECTS)

%.o : %.c %.h $(ADDHEADERS)
	$(CC) $(CFLAGS) -c $<

clean :
	$(RMRF) $(OBJECTS) $(EXECUTABLE) $(MANPAGEPS) 

