CC=vc
RMRF=rm -rf

COMMONDIR=../common/

CFLAGS=-I$(COMMONDIR)
LDFLAGS=-lamiga

OBJECTS=rvflash.o cliparse.o
ADDHEADERS=$(COMMONDIR)/config.h $(COMMONDIR)/hardware.h

EXECUTABLE=rvflash

all: $(EXECUTABLE) 

$(EXECUTABLE) : $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(LDFLAGS) $(OBJECTS)

%.o : %.c %.h $(ADDHEADERS)
	$(CC) $(CFLAGS) -c $<

clean :
	$(RMRF) $(OBJECTS) $(EXECUTABLE) $(MANPAGEPS) 

