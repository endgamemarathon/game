#include "../inc/header.h"


void print_map(t_game *game, t_list *map){
  int fd = open("./maps/map", O_RDONLY);
  char buf[1];
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
}