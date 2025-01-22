#include "so_long.h"

unsigned int get_pixel_img(t_img img, int x, int y) {
    return (*(unsigned int *)((img.addr + (y * img.line_len) + (x * img.bpp / 8))));
}

void put_pixel_img(t_img img, int x, int y, int color) {
    char *dst;

    if (color == (int)0xFF000000) // Ignore transparent pixels
        return;

    if (x >= 0 && y >= 0 && x < img.w && y < img.h) {
        dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
        *(unsigned int *)dst = color;
    }
}

void put_img_to_img(t_img dst, t_img src, int x, int y) {
    int i, j;

    for (i = 0; i < src.w; i++) {
        for (j = 0; j < src.h; j++) {
            put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
        }
    }
}

t_img load_image(void *mlx, char *path) {
    t_img img;
    img.img_ptr = mlx_xpm_file_to_image(mlx, path, &img.w, &img.h);
    if (!img.img_ptr) {
        printf("Failed to load image: %s\n", path);
        exit(1);
    }
    img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_len, &img.endian);
    return img;
}

void draw_map(t_data *data) {
    int tile_size = 50; // Each tile is 50x50 pixels
    for (int y = 0; data->map[y]; y++) {
        for (int x = 0; data->map[y][x]; x++) {
            if (data->map[y][x] == '1') {
                int screen_x = x * tile_size;
                int screen_y = y * tile_size;
                put_img_to_img(data->base_img, data->wall_img, screen_x, screen_y);
            }
        }
    }
}