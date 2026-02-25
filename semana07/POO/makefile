# Makefile 
CXX := g++

# Flags base
BASE_FLAGS := -std=c++17 -Wall -Wextra -Wpedantic

# Sistema operativo
ifeq ($(OS),Windows_NT)
    EXEEXT := .exe
    RM := del /Q
    MKDIR := mkdir
    VALGRIND := @echo "Valgrind no disponible en Windows"
else
    EXEEXT :=
    RM := rm -rf
    MKDIR := mkdir -p
    VALGRIND := valgrind --leak-check=full --show-leak-kinds=all
endif

# Archivos fuente
SRCS := $(wildcard *.cpp)
MAIN := main.cpp
OBJS := $(SRCS)

# Directorios de build
BUILD_DIR := build
NORMAL_DIR := $(BUILD_DIR)/normal
DEBUG_DIR  := $(BUILD_DIR)/debug
ASAN_DIR   := $(BUILD_DIR)/asan

MAIN := main.cpp
TARGET := $(basename $(MAIN))

.PHONY: all normal debug asan valgrind clean

# Targets públicos
all: normal

normal:
	$(MKDIR) $(NORMAL_DIR)
	$(CXX) $(BASE_FLAGS) $(SRCS) -o $(NORMAL_DIR)/$(TARGET)$(EXEEXT)

debug:
	$(MKDIR) $(DEBUG_DIR)
	$(CXX) $(BASE_FLAGS) -g -O0 $(SRCS) -o $(DEBUG_DIR)/$(TARGET)$(EXEEXT)

asan:
	$(MKDIR) $(ASAN_DIR)
	$(CXX) $(BASE_FLAGS) -fsanitize=address -fno-omit-frame-pointer -g -O1 \
	$(SRCS) -o $(ASAN_DIR)/$(TARGET)$(EXEEXT)

# Valgrind
valgrind: debug
ifeq ($(OS),Windows_NT)
	@echo "Valgrind no disponible en Windows"
else
	$(VALGRIND) ./$(DEBUG_DIR)/$(TARGET)$(EXEEXT)
endif

# Limpieza
clean:
	$(RM) build
