PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib
INC_DIR=$(PROJ_DIR)/include
BIN_DIR=$(PROJ_DIR)/bin

CC=gcc
CFLAGS=-I$(INC_DIR) -fPIC
LDFLAGS=-L$(LIB_DIR) -lmyops

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

.PHONY: clean

all: $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(OBJ_DIR)/myapp.o $(LIB_DIR)/libmyops.so.1.0
	$(CC) $< -o $@ $(LDFLAGS)

$(LIB_DIR)/libmyops.so.1.0: $(OBJ_DIR)/myadd.o $(OBJ_DIR)/mysub.o $(OBJ_DIR)/mymul.o $(OBJ_DIR)/mydiv.o $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o
	$(CC) -shared -o $@ $^
	ln -sf libmyops.so.1.0 $(LIB_DIR)/libmyops.so

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/myapp $(LIB_DIR)/libmyops*