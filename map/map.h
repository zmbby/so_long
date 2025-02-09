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
int valid_uniquechar(char c, int *b_player);
int valid_map(char **map);
t_tile  **alloc_tilemap(char **map);

t_tile  **generate_tilemap(char **map, t_game *game);
int valid_border(char**map, int y, t_vector size);

/**/
// enemy
t_enemy *new_enemy(t_enemytype type, t_tile *tile);
t_enemy *last_enemy(t_enemy *list);
void    add_enemy(t_game *game, t_enemytype type, t_tile *tile);
#endif