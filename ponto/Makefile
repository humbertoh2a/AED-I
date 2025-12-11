# Makefile para compilar main.c e Ponto.c
CC       := gcc
CFLAGS   := -std=c11 -Wall -Wextra -Wpedantic -O2
LDFLAGS  :=
LDLIBS   := -lm          # necessário para sqrt/sqrtf
TARGET   := main
OBJS     := main.o Ponto.o

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

# Regras de compilação
# main.c e Ponto.c dependem de Ponto.h
%.o: %.c Ponto.h
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
