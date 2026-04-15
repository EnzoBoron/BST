SRC = ./src/main.cpp
CC = g++
CFLAGS = -Wall

ifeq ($(OS),Windows_NT)
	EXEC_NAME = bst.exe
else
	EXEC_NAME = bst
endif

ifeq ($(OS),Windows_NT)
	RM = del /Q
else
	RM = rm -f
endif

all: $(EXEC_NAME)

$(EXEC_NAME):
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(SRC)

clean:
	$(RM) $(EXEC_NAME)

re: clean all