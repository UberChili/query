CC = g++
SRC_DIR = src
BIN_DIR = build
INCLUDE_DIR = include
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OUT = $(BIN_DIR)/query
CFLAGS = -Wall -Werror -Wextra -std=c++23 -I$(INCLUDE_DIR)

# Platform-specific settings
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    # macOS specific flags (if needed in future)
    CFLAGS += 
    LDFLAGS = 
else ifeq ($(UNAME_S),Linux)
    # Linux specific flags (if needed in future)
    CFLAGS += 
    LDFLAGS = 
else
    # Default/other platforms
    CFLAGS += 
    LDFLAGS = 
endif

# Default target: just build
all: $(OUT)

# Build target
$(OUT): $(SRC) | $(BIN_DIR)
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

# Create  builddirectory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean build artifacts
clean:
	rm -rf $(BIN_DIR)

# Optional: run target for convenience
run: $(OUT)
	./$(OUT) $(ARGS)

# Run with arguments: make run ARGS="arg1 arg2 arg3"
run-args: $(OUT)
	./$(OUT) $(ARGS)

# Phony targets
.PHONY: clean run run-args all
