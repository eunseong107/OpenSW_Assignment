PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib

CC=gcc
AR=ar

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

.PHONY: clean all basic

all: $(BIN_DIR)/mycalculate

$(BIN_DIR)/mycalculate: $(LIB_DIR)/libmybasic.a $(OBJ_DIR)/myapp.o
	$(CC) $(OBJ_DIR)/myapp.o $(LIB_DIR)/libmybasic.a -o $(BIN_DIR)/mycalculate -L$(LIB_DIR) -lmybasic

$(OBJ_DIR)/myapp.o: $(SRC_DIR)/myapp.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/myapp

basic:
	$(CC) -c $(SRC_DIR)/add.c -o $(OBJ_DIR)/add.o -I$(INC_DIR)
	$(CC) -c $(SRC_DIR)/div.c -o $(OBJ_DIR)/div.o -I$(INC_DIR)
	$(CC) -c $(SRC_DIR)/mul.c -o $(OBJ_DIR)/mul.o -I$(INC_DIR)
	$(CC) -c $(SRC_DIR)/sub.c -o $(OBJ_DIR)/sub.o -I$(INC_DIR)
	$(AR) rv $(LIB_DIR)/libmybasic.a $(OBJ_DIR)/add.o $(OBJ_DIR)/div.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/sub.o