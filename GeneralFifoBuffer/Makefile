TARGET=a.out

DEPENDLIST = depend.inc
OBJS = main.o fifo.o fifoAllocator.o
INCLUDES = -Iinclude
LIBS = -L/usr/local/lib
CFLAGS = -O2 -Wall -Wno-pointer-sign
LFLAGS =
CC = gcc
.SUFFIXES: .c .o

.PHONY: all depend clean run
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LIBS) $(CFLAGS) -o $(TARGET) $^ $(LFLAGS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

clean:
	$(RM) $(OBJS) $(TARGET) $(DEPENDLIST)

run: $(TARGET)
	./$(TARGET)

# gcc -L /usr/local/lib/ -lpthread -lpaho-mqtt3c -Iinclude $^

# ヘッダ依存関係の解決(ヘッダに変更があったらリビルドされる)
.PHONY: $(DEPENDLIST)
$(DEPENDLIST): $(OBJS:.o=.c) 
	-@ $(RM) depend.inc
	-@ for i in $^; do cpp -MM $$i $(INCLUDES) | sed "s/\ [_a-zA-Z0-9][_a-zA-Z0-9]*\.c//g" >> $(DEPENDLIST); done

include $(DEPENDLIST)