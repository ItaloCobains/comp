CXX = g++
CXXFLAGS = -std=c++2b -Wall -Wextra -g
OUTPUT = output
SRC = src
INCLUDE = include
LIB = lib

LIBBITWISEHASH_DIR = $(LIB)
LIBBITWISEHASH = -L$(LIBBITWISEHASH_DIR) -lbitwisehash

MAIN = $(OUTPUT)/main

SOURCEDIRS = $(shell find $(SRC) -type d)
INCLUDEDIRS = $(shell find $(INCLUDE) -type d)

FIXPATH = $(subst /,\,$1)
RM = rm -f
MD = mkdir -p

SOURCES = $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))
OBJECTS = $(SOURCES:.cpp=.o)
DEPS = $(OBJECTS:.o=.d)

OUTPUTMAIN = $(MAIN)  # Correção aqui

all: $(OUTPUT) $(MAIN)
	@echo Executing 'all' complete!

$(OUTPUT):
	$(MD) $(OUTPUT)

$(MAIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LIBBITWISEHASH) $(LFLAGS) $(LIBS)

-include $(DEPS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -MMD $< -o $@ $(LIBBITWISEHASH)

.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	$(RM) $(call FIXPATH,$(DEPS))
	@echo Cleanup complete!

run: all
	./$(OUTPUTMAIN)
	@echo Executing 'run: all' complete!
