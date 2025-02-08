#ifndef MAP_H
#define MAP_H

#include "../so_long.h"
#include "../basics.h"

typedef struct s_tile t_tile;
typedef struct s_game t_game;

typedef struct s_mapchecker
{
    t_vector    size;
    t_vector    point;
    int         b_player;
    int         b_exit;
    int         b_collect;
} t_mapchecker;

// map functions
int valid_file(int ac, char *file);
char    **read_map(char *file);
int valid_char(char c);
int valid_uniquechar(char c, char checker, int bool);
int valid_map(char **map);
t_tile  **alloc_tilemap(char **map);
t_tile  **generate_tilemap(char **map, t_game);
int valid_border(char c, t_vector point, t_vector size);

#endif