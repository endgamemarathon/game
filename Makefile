CC = clang

CFLAGS = -std=c11 #-Wall -Wextra -Werror -Wpedantic

SDL2 = -I ./Frameworks/SDL2.framework/Versions/A/Header -F ./Frameworks -framework SDL2
SDL2_IMAGE = -I ./Frameworks/SDL2_image.framework/Versions/A/Header -F ./Frameworks/ -framework SDL2_image
SDL2_TTF = -I ./Frameworks/SDL2_ttf.framework/Versions/A/Headers -F ./Frameworks/ -framework SDL2_ttf

SOURCES=main.c mx_push_back.c mx_create_node.c mx_printerr.c mx_strlen.c

OBJECTS=$(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))
OBJ_DIR=./obj/
SRC_DIR=./src/
HEADER=./inc/header.h


EXECUTABLE = endgame


all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(SDL2) $(SDL2_IMAGE) $(SDL2_TTF) -rpath ./Frameworks

$(OBJECTS): $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@ $(SDL2) $(SDL2_IMAGE) $(SDL2_TTF) -rpath ./Frameworks

uninstall:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)

clean: 
	rm -rf $(OBJ_DIR)

reinstall: uninstall all
