# Variables
NAME = battle

CC = gcc
CFLAGS = -c -Wall -Werror -g -std=c11 -pedantic-errors -Iinclude
LD = gcc

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

TARGET = $(BIN_DIR)/$(NAME)

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Targets and rules
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(LD) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

help:
	@echo "Makefile for Battle Project"
	@echo "Targets:"
	@echo "  all      - Compile and link the Battle program"
	@echo "  clean    - Remove compiled files"
	@echo "  help     - Show this help message"

.PHONY: all clean help
