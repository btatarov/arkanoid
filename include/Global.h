
#ifndef GLOBAL_H_INCLUDED

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAXX  (13*TILE_WIDTH)
#define MAXY  (30*TILE_HEIGHT)

#define TILE_WIDTH (SCREEN_WIDTH/15)
#define TILE_HEIGHT (SCREEN_HEIGHT/35)

#define BASE_PADDLE_WIDTH (2*TILE_WIDTH)
#define BASE_PADDLE_HEIGHT (3*TILE_HEIGHT / 2)
#define PADDLE_OFFSET_FROM_TOP (23*TILE_HEIGHT)
#define PADDLE_SPEED 5

#define BALL_HEIGHT 6
#define BALL_WIDTH 6
#define BALL_SPEED_X 3
#define BALL_SPEED_Y 3

#define RESPAWN_TIME_IN_FRAMES 60

#define FPS 60
#define SPF (1./FPS)
#endif
