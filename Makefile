
# variaveis
CC = gcc
CFLAGS = -Wall -g

TARGET = main

SRCDIR = source
OBJDIR = obj
INCDIR = headers

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS)) $(OBJDIR)/$(TARGET).o
HEADERS = $(wildcard $(INCDIR)/*.h)

RM = rm -f

all: $(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

# compilacao (.c -> .o)
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/$(TARGET).o: $(TARGET).c $(HEADERS) | $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

# linkagem (.o -> executavel)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# outras regras
clean:
	$(RM) $(OBJS) $(TARGET) $(TARGET).exe

run: 
	./$(TARGET)