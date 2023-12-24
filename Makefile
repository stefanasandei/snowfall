CC       	= gcc
CFLAGS   	= -std=c99
LFLAGS   	= -lm -lncursesw

TARGET    = snowfall
SRC_DIR   = src
BIN_DIR   = bin
OBJ_DIR   = $(BIN_DIR)

SRC      	= $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
OBJ      	= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: run clean

.DEFAULT_GOAL = run

build: $(BIN_DIR) $(BIN_DIR)/$(TARGET)

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@

$(BIN_DIR)/$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $@

run: build
	./$(BIN_DIR)/$(TARGET)

clean:
	rm -f $(OBJ)

