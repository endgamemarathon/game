#include "../inc/header.h"

void default_position_topi(t_topiman *topiman) //место спавна topi
{
  topiman->topi = (t_pos){20, 20};
  topiman->topiMove = (t_pos){-1, 0};
}

static void initDefault(t_topiman *topiman, t_game *game, int *stop)
{ 
  *stop = 0;
  
  default_position_topi(topiman);
  
  topiman->topiImage = IMG_Load("image/Topi1.png"); //подключение картинок
  topiman->topiImageDown1 = IMG_Load("image/Topi2.png");
  topiman->topiImageDown2 = IMG_Load("image/Topi3.png");
  topiman->topiImageUp1 = IMG_Load("image/Topi_S1.png");
  topiman->topiImageUp2 = IMG_Load("image/Topi_S2.png");
  topiman->topiImageUp3 = IMG_Load("image/Topi_S3.png");
  topiman->topiImageLeft1 = IMG_Load("image/Topi_L1.png");
  topiman->topiImageLeft2 = IMG_Load("image/Topi_L2.png");
  topiman->topiImageLeft3 = IMG_Load("image/Topi_L3.png");
  topiman->topiImageRight1 = IMG_Load("image/Topi_P1.png");
  topiman->topiImageRight2 = IMG_Load("image/Topi_P2.png");
  topiman->topiImageRight3 = IMG_Load("image/Topi_P3.png");
  topiman->topiTexture = SDL_CreateTextureFromSurface(game->sdl.renderer, topiman->topiImageLeft1); //cоздание текстуры
}



int main(int argc, char **argv){
  if (argc != 2) {
    return -1;
  }
  t_list    *map;
  t_game    *game;
  int       stop;
  t_topiman *topiman;
  
  game = (t_game *)malloc(sizeof(t_game));
  topiman = (t_topiman *)malloc(sizeof(t_topiman));
  init_map(argv[1], map, game);

  initSDL(game); //инициализации SDL

  SDL_Init(SDL_INIT_EVERYTHING);



  // SDL_Surface *scr = NULL;
  SDL_Surface *wall = NULL;
  SDL_Surface *coin = NULL;
  
  // scr = SDL_GetWindowSurface(game->sdl.window);
  wall = IMG_Load("3.bmp");
  coin = IMG_Load("8.bmp");
  
  SDL_Texture *t_wall;
  SDL_Texture *t_coin;
  t_wall = SDL_CreateTextureFromSurface(game->sdl.renderer, wall);
  t_coin = SDL_CreateTextureFromSurface(game->sdl.renderer, coin);
  // wall = SDL_ConvertSurface(wall, scr->format, 0);
  // coin = SDL_ConvertSurface(coin, scr->format, 0);
  initDefault(topiman, game, &stop);
  // render_map(map, scr, wall, coin, topiman);
  SDL_RenderCopy(game->sdl.renderer, topiman->topiTexture, NULL, &(topiman->topiRect));

  // SDL_UpdateWindowSurface(game->sdl.window);

  // while (1){    
    // if ( SDL_PollEvent( &windowEvent ) ) {
      // if ( SDL_QUIT == windowEvent.type ) {
      	// break;
      // }
    // }
  // }
  
  // SDL_DestroyWindow(game->sdl.window);
  // SDL_Quit( );
  // return EXIT_SUCCESS;


//-----------------------
  

//   initDefault(topiman, &stop);
  
  while (!stop)
  {
    while (SDL_PollEvent(&(game->sdl.e))) //опрос события
    {
      if (game->sdl.e.type == SDL_QUIT || game->sdl.e.key.keysym.sym == SDLK_ESCAPE) //выйти из игры
        stop = 1;
      else if (game->sdl.e.type == SDL_KEYUP)
      {
        if (game->sdl.e.key.keysym.sym == SDLK_DOWN) //главное управление
          topiman->topiMove = (t_pos){0, 1};
        else if (game->sdl.e.key.keysym.sym == SDLK_UP)
          topiman->topiMove = (t_pos){0, -1};
        else if (game->sdl.e.key.keysym.sym == SDLK_RIGHT)
          topiman->topiMove = (t_pos){1, 0};
        else if (game->sdl.e.key.keysym.sym == SDLK_LEFT)
          topiman->topiMove = (t_pos){-1, 0};
      }
    }
    // render_clearSDL(game); //очистка цели рендеринга
    // render_map(map, scr, t_wall, t_coin, game);
    // mx_topi(topiman); //поведение topi
    // mx_map(topiman); //обращение к карте

    SDL_RenderPresent(game->sdl.renderer); //рендеринг
    SDL_Delay(240); //скорость передвижения
  }
  destroySDL(game); //закрывает окно
}
