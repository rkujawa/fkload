CC=vc
RMRF=rm -rf

CFLAGS=-I../../
LDFLAGS=-lamiga

OBJECTS=rv_flashid.o
ADDHEADERS=config.h hardware.h

EXECUTABLE=rvflash

all: $(EXECUTABLE) 

$(EXECUTABLE) : $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(LDFLAGS) $(OBJECTS)

%.o : %.c %.h $(ADDHEADERS)
	$(CC) $(CFLAGS) -c $<

clean :
	$(RMRF) $(OBJECTS) $(EXECUTABLE) $(MANPAGEPS) 

