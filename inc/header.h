#ifndef ENDGAME_HEADER
#define ENDGAME_HEADER

#define SCREEN_WIDTH 2280
#define SCREEN_HEIGHT 920
#define WALL_WIDTH 12
#define LINE_WIDTH 6
//#define PLAYER_WIDTH 50
//#define VIRUS_WIDTH 30
//#define PLAYER_STEP 8
//#define VIRUS_STEP 4

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include <fcntl.h>
#include <stdlib.h>
#include "ctype.h"
#include "unistd.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <time.h>

typedef struct s_game {
  int size_x;
  int size_y;
} t_game;

typedef struct s_point {
  int x;
  int y;
  int is_wall;
  int is_coin;
} t_point;

typedef struct s_list {
  void *data;
  struct s_list *next;
} t_list;

void mx_printerr(const char *s);
t_list *mx_create_node(void *data);
void mx_push_back(t_list **list, void *data);
int mx_strlen(const char *s);
#endif
