PROJECT_NAME = MatrixOperations

#Source Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

#Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror -I$(INCLUDE_DIR) -g

#Source Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

#executable
EXECUTABLE = $(PROJECT_NAME)

#Default Target
all: $(EXECUTABLE)

#Create build directory if they don't exist
$(BUILD_DIR) $(OBJ_DIR):
	mkdir -p $@

#Link obkect files to create executable
$(EXECUTABLE): $(OBJ_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

#Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

#Clean
clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)

#Run
run: 
	./$(EXECUTABLE)

#Debug target to compile with debug flags
debug: CXXFLAGS += -g
debug: all

#show me executable
show:
	@echo $(EXECUTABLE)