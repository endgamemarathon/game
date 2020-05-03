#ifndef ENDGAME_HEADER
#define ENDGAME_HEADER

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 750
#define WALL_WIDTH 12
#define LINE_WIDTH 6

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

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		e;
	// TTF_Font		*font;
	//SDL_Surface		*surfaceScore;
//	SDL_Rect		rectScore;
//	SDL_Texture		*textureScore;
}					t_sdl;

typedef struct s_game {
  int 	size_x;
  int 	size_y;
  t_sdl	sdl;

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


typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_topiman
{
	t_pos			topi;
	t_pos			topiMove;
	SDL_Surface		*topiImage;
	SDL_Surface		*topiImageUp1;
	SDL_Surface		*topiImageUp2;
	SDL_Surface		*topiImageUp3;
	SDL_Surface		*topiImageDown1;
	SDL_Surface		*topiImageDown2;
	SDL_Surface		*topiImageLeft1;
	SDL_Surface		*topiImageLeft2;
	SDL_Surface		*topiImageLeft3;
	SDL_Surface		*topiImageRight1;
	SDL_Surface		*topiImageRight2;
	SDL_Surface		*topiImageRight3;
	SDL_Texture		*topiTexture;
	SDL_Rect		topiRect;

	int				stop;

}					t_topiman;


void mx_printerr(const char *s);
t_list *mx_create_node(void *data);
void mx_push_back(t_list **list, void *data);
int mx_strlen(const char *s);
void init_map(char *filename, t_list *map, t_game *game);
void render_map(t_list *map, SDL_Surface *scr, SDL_Texture *wall, SDL_Texture *coin, t_game *game);

// start
void				initSDL(t_game *game);
void				destroySDL(t_game *game);
void				render_clearSDL(t_game *game);

void				default_position_topi(t_topiman *topiman);

void				mx_map(t_topiman *topiman);
void				mx_topi(t_topiman *topiman);
// end

#endif
