############################################################################################
################################## GENERIC MAKEFILE ########################################
############################################################################################
# TODO: g�rer les sous-dossiers / fichiers ayants le mêmes noms dans des dossiers différen
# TODO: g�rer les extentions .hpp, .cxx, ...

# Debug mode (comment this line to build project in release mode)
DEBUG = true

# Compiler
CC = g++
# Command used to remove files
RM = rm -f
# Compiler and pre-processor options
CPPFLAGS = -Wall -std=c++17 -O0
# Add -Ofast for opt
# Debug flags
DEBUGFLAGS = -g
# Resulting program file name
EXE_NAME = c_gram_comp
# The source file extentions
SRC_EXT = cpp
# The header file types
# TODO allow .hpp header files
HDR_EXT = h

# Source directory
SRCDIR = source
# Headers directory
INCDIR = headers
# Main output directory
OUTPUT_DIR = bin
# Release output directory
RELEASEDIR = release
# Debug output directory
DEBUGDIR = debug
# Dependency files directory
DEPDIR = dep
# Libraries paths
LIBS = #-l
# List of include paths
INCLUDES = ./$(INCDIR)

ifdef DEBUG
BUILD_PATH = ./$(OUTPUT_DIR)/$(DEBUGDIR)
else
DEBUGFLAGS = 
BUILD_PATH = ./$(OUTPUT_DIR)/$(RELEASEDIR)
endif
# Source directory path
SRC_PATH = ./$(SRCDIR)
# Dependencies path
DEP_PATH = ./$(BUILD_PATH)/$(DEPDIR)

# List of source files
SOURCES = $(wildcard $(SRC_PATH)/*.$(SRC_EXT))
# List of object files
OBJS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)
# List of dependency files
DEPS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(DEP_PATH)/%.d)

.PHONY: all clean rebuild help

all: $(BUILD_PATH)/$(EXE_NAME)

clean:
	$(RM) $(BUILD_PATH)/*.o
	$(RM) $(BUILD_PATH)/$(EXE_NAME)
	$(RM) $(DEP_PATH)/*.d
	
rebuild: clean all

help:
	@echo '				### MAKEFILE HELP ###'
	@echo 'PHONY TARGETS:'
	@echo '	all 	...'
	@echo '	clean 	...'
	@echo '	rebuild ...'
	@echo '	help	...'

# Build object files
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@mkdir -p $(DEP_PATH)
	$(CC) $(CPPFLAGS) $(DEBUGFLAGS) -I $(INCLUDES) $(LIBS) -MMD -MP -MF $(DEP_PATH)/$*.d -c $< -o $@

# Build main target
$(BUILD_PATH)/$(EXE_NAME): $(OBJS)
	$(CC) $(OBJS) -o $(BUILD_PATH)/$(EXE_NAME)
