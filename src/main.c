
#include <stdio.h>
#include "../inc/header.h"
void place_image(int x, int y, SDL_Surface *scr, SDL_Surface *image) {
  SDL_Rect bg_image;
  bg_image.w = WALL_WIDTH;
  bg_image.h = WALL_WIDTH;
  bg_image.x = x * WALL_WIDTH;
  bg_image.y = y * WALL_WIDTH;
  SDL_BlitScaled(image, NULL, scr, &bg_image);
}


int main(int argc, char **argv){
  if (argc != 2) {
    return -1;
  }
  int fd = open(argv[1], O_RDONLY);
  char buf[1];
  t_game *game = (t_game *)malloc(sizeof(t_game));
  t_list *map;
  t_list *tmp;
  game->size_x = 0;
  game->size_y = 0;
  while (read(fd, buf, 1) == 1) {
    if (*buf == '\n') {
      game->size_y++;
      if(game->size_x * WALL_WIDTH > SCREEN_WIDTH) {
        mx_printerr("To much\n");
	exit(-1);
      } 
      game->size_x = 0;
      continue;
    }
    t_point *point = (t_point *)malloc(sizeof(t_point));
    point->y = game->size_y;
    point->x = game->size_x;
    if(*buf - 48 == 1) {
      point->is_wall = 1;
      point->is_coin = 0;
    }
    else if(*buf - 48 == 2){
      point->is_wall = 0;
      point->is_coin = 1;
    } else {
      point->is_wall = 0;
      point->is_coin = 0;
    }
    if (!map){
      map = mx_create_node(point);
      tmp = map;
    } else {
      map->next = mx_create_node(point);
      map = map->next;
    }
    game->size_x++;
  }
  if(game->size_y * WALL_WIDTH > SCREEN_HEIGHT) {
    mx_printerr("To much\n");
    exit(-1);
  }
  map = tmp;

  close(fd);
  SDL_Init( SDL_INIT_EVERYTHING );
  SDL_Window *window = SDL_CreateWindow( "Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
  SDL_Surface *scr = NULL;
  SDL_Surface *wall = NULL;
  SDL_Surface *coin = NULL;
  scr = SDL_GetWindowSurface(window);
  wall = IMG_Load("3.bmp");
  coin = IMG_Load("8.bmp");
  wall = SDL_ConvertSurface(wall, scr->format, 0);
  coin = SDL_ConvertSurface(coin, scr->format, 0);
  SDL_Event windowEvent;
  t_point *t;
  while (tmp) {
    t = (t_point*)tmp->data;
    if (t->is_wall) {
      place_image(t->x, t->y, scr, wall);
    }
    else if(t->is_coin) {
      place_image(t->x, t->y, scr, coin);
    }
    tmp = tmp->next;
  }
  SDL_UpdateWindowSurface(window);


  while (1){    
    if ( SDL_PollEvent( &windowEvent ) ) {
      if ( SDL_QUIT == windowEvent.type ) {
	break;
      }
    }
  }
  
  SDL_DestroyWindow( window );
  SDL_Quit( );
  return EXIT_SUCCESS;
}
