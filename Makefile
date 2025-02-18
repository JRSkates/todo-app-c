CC = gcc

SRC = src/main.c src/db.c src/tasks.c
EXEC = todo

all: $(EXEC)

$(EXEC): ${SRC}
		$(CC) $(SRC) -o $(EXEC)

clean:
		rm -f (EXEC)