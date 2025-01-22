#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/X.h>       // For KeyPress, KeyRelease, etc.
#include <X11/keysym.h>  // For keycodes like XK_Escape, XK_Left, etc.
#include <fcntl.h>
#include <unistd.h>
#include "../get_next_line/get_next_line.h"

// Window dimensions and speed
#define SPEED 15

// Keycodes for Linux
#define KEY_ESC 65307
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_DOWN 65364
#define KEY_UP 65362

// Structure for image data
typedef struct s_img {
    void    *img_ptr;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    int     w;
    int     h;
} t_img;

// Structure for game data
typedef struct s_data {
    void    *mlx;
    void    *win;
    t_img   base_img; // Base image for rendering
    t_img   idle_frames[4][8]; // Idle animation frames
    t_img   running_frames[4][8]; // Running animation frames
    int     current_frame;  // Index of the current frame
    int     loop_counter;  // Counter to control the frame rate
    int     direction;     // Current direction: 0 = down, 1 = left, 2 = right, 3 = up
    int     state;  // Current state: 0 = idle, 1 = running
    int     x;
    int     y;
    int     win_width; // Window width
    int     win_height; // Window height
    t_img   wall_img; // Wall image
    char    **map;
} t_data;

// Function prototypes
void update_position(t_data *data);
int render_next_frame(void *param);
int handle_key_press(int keycode, t_data *data);
int handle_key_release(int keycode, t_data *data);
int handle_exit(t_data *data);
int check_ber(char *map);
int loop_x1(char **tab, int y, int x, int i);
int check_valid(char *map);
int check_map(char *map);
char **read_map(char *map_file);
void draw_map(t_data *data);
t_img load_image(void *mlx, char *path);
void put_img_to_img(t_img dst, t_img src, int x, int y);
unsigned int get_pixel_img(t_img img, int x, int y);
void put_pixel_img(t_img img, int x, int y, int color);

#endif