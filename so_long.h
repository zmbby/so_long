#ifndef SO_LONG_H
#define SO_LONG_H

#include "game/game.h"
#include "map/map.h"
#include "basics.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <fcntl.h>

# define IMG_SIZE 64

typedef enum s_tiletype
{
    EMPTY = '0',
    WALL = '1',
    COIN = 'C',
    PLAYER = 'P',
    EXIT = 'E',
    ENEMY = 'M',
    FOLLOWER = 'F',
} t_tiletype;

typedef struct s_tile
{
    t_tiletype  type;
    t_tiletype  og_type;
    t_vector    position;
    struct s_tile   *up;
    struct s_tile   *down;
    struct s_tile   *left;
    struct s_tile   *right;
} t_tile;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_vector    win_size;
    t_tile      **tilemap;
    int         collects;
    int         moves;
} t_game;

// functions 
int error(char *msg);

#endif