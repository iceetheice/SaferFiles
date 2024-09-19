CC = gcc
CFLAGS = -c -std=c99
LDFLAGS = -lraylib -lgdi32 -lwinmm -Wl,-subsystem,console

EXEC = SaferFiles.exe

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
