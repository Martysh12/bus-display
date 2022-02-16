CXX := g++
CXXFLAGS := -Wall

RM := del /s /q

BIN_DIR := bin
OBJ_DIR := obj
SRC_DIR := src

EXE := $(BIN_DIR)/bus_hud.exe

SRC := $(wildcard $(SRC_DIR)/*.cpp)

OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(EXE)

.PHONY: all

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -g -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)

