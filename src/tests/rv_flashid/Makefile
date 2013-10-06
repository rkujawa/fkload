CC=vc
RMRF=rm -rf

COMMON=../../common

CFLAGS=-I$(COMMON)
LDFLAGS=-lamiga

OBJECTS=rv_flashid.o
COMMONOBJECTS=$(COMMON)/flash.o
ADDHEADERS=$(COMMON)/config.h $(COMMON)/hardware.h $(COMMON)/flash.h $(COMMON)/mx29lv640.h

EXECUTABLE=rv_flashid

all: $(EXECUTABLE) 

$(EXECUTABLE) : $(OBJECTS) $(COMMONOBJECTS)
	$(CC) -o $(EXECUTABLE) $(LDFLAGS) $(OBJECTS) $(COMMONOBJECTS)

%.o : %.c %.h $(ADDHEADERS)
	$(CC) $(CFLAGS) -c $<

clean :
	$(RMRF) $(OBJECTS) $(EXECUTABLE) $(MANPAGEPS) 

