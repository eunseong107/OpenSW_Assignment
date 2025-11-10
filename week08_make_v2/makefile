PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib
STATIC_LIBS=$(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a

CC=gcc
CFLAGS=-I$(INC_DIR) -lm
LDFLAGS=-L$(LIB_DIR) -lmybasic -lmyadvanced
AR=ar

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

.PHONY: clean all basic_ops advanced_ops

all: basic_ops advanced_ops $(BIN_DIR)/mycalculate

$(BIN_DIR)/mycalculate: $(OBJ_DIR)/myapp.o $(STATIC_LIBS)
	$(CC) $< -o $@ $(LDFLAGS) $(CFLAGS)

$(OBJ_DIR)/myapp.o: $(SRC_DIR)/myapp.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean

basic_ops:
	$(MAKE) -C basic_ops

advanced_ops:
	$(MAKE) -C advanced_ops