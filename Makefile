CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lsqlite3

SRC = src/main.c src/db.c src/tasks.c
OBJ = $(SRC:.c=.o)
TARGET = todo

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJ)
