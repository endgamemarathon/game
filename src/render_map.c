#include "../inc/header.h"

void place_image(int x, int y, SDL_Surface *scr, SDL_Surface *image) {
  SDL_Rect bg_image;
  bg_image.w = WALL_WIDTH;
  bg_image.h = WALL_WIDTH;
  bg_image.x = x * WALL_WIDTH;
  bg_image.y = y * WALL_WIDTH;
  SDL_BlitScaled(image, NULL, scr, &bg_image);
}

void render_map(t_list *map, SDL_Surface *scr, SDL_Texture *wall, SDL_Texture *coin, t_game *game) {

  t_point *t;
  t_list *tmp;

  SDL_Surface *wall2 = NULL;
  SDL_Surface *coin2 = NULL;

  wall2 = IMG_Load("3.bmp");
  coin2 = IMG_Load("8.bmp");
  SDL_Texture *t_wall;
  SDL_Texture *t_coin;
  t_wall = SDL_CreateTextureFromSurface(game->sdl.renderer, wall2);
  t_coin = SDL_CreateTextureFromSurface(game->sdl.renderer, coin2);

  SDL_Rect  rect;
  SDL_Rect  wall_rect;
  SDL_Rect  coin_rect;

  rect = (SDL_Rect) {0, 0, 60, 60};
  wall_rect = (SDL_Rect) {0, 0, 60, 60};
  coin_rect = (SDL_Rect) {0, 0, 60, 60};
  tmp = map;
  while (tmp) {
    
    t = (t_point*)tmp->data;
    if (t->is_wall) {
      wall_rect = (SDL_Rect) {t->x, t->y, 60, 60};
      SDL_RenderCopy(game->sdl.renderer, t_wall, NULL, &(wall_rect));
      // place_image(t->x, t->y, scr, wall);
    }
    else if(t->is_coin) {
      // place_image(t->x, t->y, scr, coin);
      coin_rect = (SDL_Rect) {t->x, t->y, 60, 60};
      SDL_RenderCopy(game->sdl.renderer, t_coin, NULL, &(coin_rect));
    }
    tmp = tmp->next;
  }
  // place_image(topiman->topi.x, topiman->topi.y, scr, topiman->topiImage);
}