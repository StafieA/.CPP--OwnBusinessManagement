# Define the compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Define the directories
APP_DIR = gm.app
DATA_DIR = gm.data

# Define the source files
SOURCES = $(APP_DIR)/Shop.cpp \
          $(DATA_DIR)/Product.cpp \
          $(DATA_DIR)/Food.cpp \
          $(DATA_DIR)/Drink.cpp \
          $(DATA_DIR)/Utils.cpp \
          $(DATA_DIR)/ProductManager.cpp \
          $(DATA_DIR)/Review.cpp \
          $(DATA_DIR)/Rating.cpp

# Define the object files
OBJECTS = $(SOURCES:.cpp=.o)

# Define the target executable
TARGET = ShopApp.exe

# Rule to build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Pattern rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

