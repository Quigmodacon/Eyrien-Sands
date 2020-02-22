SRC_DIR := ./definitions
OBJ_DIR := ./obj
HPP_DIR := ./headers
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

Eyrien_Sands: $(OBJ_FILES)
	clang++ -o $@ $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	clang++ -c -o $@ $<