CC = gcc
CFLAGS = -Wall -g
SRCDIR = src
INCDIR = header
OBJDIR = obj

SRCS = $(wildcard $(SRCDIR)/graphe.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
DEPS = $(wildcard $(INCDIR)/*.h)

TARGET = graphe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)
