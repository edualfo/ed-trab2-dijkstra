
# variaveis
CC = gcc
CFLAGS = -Wall -g

RM = rm -f


TARGET = main

SRCDIR = source
OBJDIR = obj
INCDIR = headers


SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS)) $(OBJDIR)/$(TARGET).o
HEADERS = $(wildcard $(INCDIR)/*.h)


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


# execucao
run: 
	./$(TARGET)