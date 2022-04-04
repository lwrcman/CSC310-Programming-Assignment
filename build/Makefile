# makefile

EXECUTABLE_NAME = project

INC = ../includes
SRC = ../src

OBJ_DIR = objects

HEADERS = $(wildcard $(INC)/*/*.h)
SOURCES = $(wildcard $(SRC)/*/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

CC = gcc
CFLAGS = -lm -O1

.PHONY: clean build

build: $(OBJECTS) $(HEADERS)
	$(CC) $(OBJECTS) -I $(SRC) -I $(INC) $(CFLAGS) -o $(EXECUTABLE_NAME)

$(OBJ_DIR)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) -I $(SRC) -I $(INC) $(CFLAGS) -c $< -o $@

clean:
	rm -fR $(OBJECTS) $(EXECUTABLE_NAME)

clean_project:
	rm -fR ${EXECUTABLE_NAME}