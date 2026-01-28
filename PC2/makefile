# Compilador
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic
ASANFLAGS := -fsanitize=address -g -O1

# Detectar sistema operativo
ifeq ($(OS),Windows_NT)
    EXEEXT := .exe
else
    EXEEXT :=
endif

SRCS := $(wildcard *.cpp)
TARGETS := $(SRCS:%.cpp=%$(EXEEXT))

# Por defecto
all: $(TARGETS)

# Regla normal
%$(EXEEXT): %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Regla con ASan
asan: CXXFLAGS += $(ASANFLAGS)
asan: clean all

clean:
	rm -f $(TARGETS)