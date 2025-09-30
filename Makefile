CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRC = $(wildcard src/*.cpp)
TARGET = KnightMare

all:	$(TARGET)
		@echo "Build successfull! Running $(TARGET)..."
		./$(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean: 
	$(RM) $(TARGET)
	@echo "Cleaned Build Artifacts"