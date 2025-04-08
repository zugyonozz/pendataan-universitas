# Compiler dan flags
CXX := g++
CC := gcc
CXXFLAGS := -std=c++17 -Wall -Iinclude -Iinclude/sqlite -Iinclude/SDL
LDFLAGS := -Llib -lSDL3 -lSDL3_image -lSDL3_ttf

# Folder dan target
SRC_DIR := src
BIN_DIR := bin
TARGET := $(BIN_DIR)/akademik

# Sumber dan objek
SRCS := $(wildcard $(SRC_DIR)/*.cpp) \
        $(SRC_DIR)/sqlite3.c
OBJS := $(SRCS:.cpp=.o)
OBJS := $(OBJS:.c=.o)

# Build default
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	@echo Linking...
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile C++
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo Compiling C++: $<
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile C
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling C: $<
	$(CC) $(CXXFLAGS) -c $< -o $@

# Jalankan program
run: all
	@echo Running...
	./$(TARGET)

# Bersihkan file
clean:
	@echo Cleaning...
	rm -f $(OBJS) $(TARGET)