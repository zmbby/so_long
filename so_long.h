#ifndef SO_LONG_H
#define SO_LONG_H


#include "basics.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

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


typedef struct s_panel
{
	void		*pointer;
	char		*pixels;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
}	t_panel;

// ------------------- colors

typedef struct s_color
{
    int r;
    int g;
    int b;
    int a;
}   t_color;


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

typedef struct s_player
{
    t_tile  *tile;
    void    *current_img;
    int     framecount;
    int     idle_frames;
    void    *idle_img_0;
    void    *idle_img_1;
    int     action_frames;
    void    *action_img;
}   t_player;

typedef enum e_enemytype
{
    HORIZONTAL_ENEM = 'H',
	VERTICAL_ENEM = 'V',
	FOLLOW_ENEM = 'F'
}   t_enemytype;

typedef struct s_wall_img
{
    void	*block;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
}   t_wall_img;

typedef struct s_enemy
{
    t_enemytype     type;
    int             dir;
    t_tile          *og_tile;
    t_tile          *tile;
    struct s_enemy  *next;
}   t_enemy;

typedef struct s_collect_img
{
    void    *current_img;
    int     anim_frames;
    void    *img_0;
    void    *img_1;
}   t_collect_img;

typedef struct s_enemy_img
{
	int		basic_anim;
	void	*basic_current;
	void	*basic_01;
	void	*basic_02;
	int		follow_anim;
	void	*follow_current;
	void	*follow_01;
	void	*follow_02;
}	t_enemy_img;

typedef struct s_effect
{
	void		*img;
	t_vector	pos;
	int			frames;
	int			counter;
}	t_effect;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_vector    win_size;
    t_tile      **tilemap;
    t_player    player;
    int         og_collects;
    int         collects;
    int         moves;
    t_enemy			*enemy_list;
	t_vector		img_size;
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	t_enemy_img		enemy_imgs;
	void			*door_open_img;
	void			*door_close_img;
	t_effect		effect;
	void			*red_panel;
	void			*white_panel;
} t_game;

// functions 
int error(char *msg);
void	*null_error(char *message);
void	print_warning(char *message);

#endif