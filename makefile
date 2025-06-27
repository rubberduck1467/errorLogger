vpath %.h ../include
CC := gcc

TARGET_EXE := test.out
DEBUG_EXE := debug.out
LIB_TARGET := logger.so

BUILD_DIR := .
SRC_DIRS := .


SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

#debug build
$(BUILD_DIR)/$(DEBUG_EXE): $(OBJS:%=%.debug)
	@$(CC) $^ -o $@

#debug compile
$(BUILD_DIR)/%.c.o.debug: %.c
	@mkdir -p $(dir $@)
	@$(CC) $< -c -g -o $@

#standard build
$(BUILD_DIR)/$(TARGET_EXE): $(OBJS)
	@$(CC) $^ -s -o $@	

#standard compile
$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) -fPIC -shared $< -c -o $@

#build so
$(BUILD_DIR)/$(LIB_TARGET): $(SRCS)
	@$(CC) -fPIC -shared $^ -o $@	

.PHONY: clean
clean:
	@rm -rf *.o *.debug *.out

