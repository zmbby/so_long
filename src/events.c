#include "so_long.h"

void update_position(t_data *data) {
    if (data->state == 0)
        return;
    if (data->direction == 0 && data->y + SPEED + 130 < data->win_height)
        data->y += SPEED;
    if (data->direction == 1 && data->x - SPEED > 0)
        data->x -= SPEED;
    if (data->direction == 2 && data->x + SPEED + 64 < data->win_width)
        data->x += SPEED;
    if (data->direction == 3 && data->y - SPEED > 0)
        data->y -= SPEED;
}
int render_next_frame(void *param) {
    if (param == NULL) {
        printf("render_next_frame: param is NULL\n");
        return (1);
    }
    t_data *data = (t_data *)param;
    data->loop_counter++;

    if (data->loop_counter % 3000 == 0) { // Adjust modulo for smoother animation
        update_position(data);

        if (data->base_img.img_ptr == NULL) {
            printf("render_next_frame: base_img.img_ptr is NULL\n");
            return (1);
        }
        put_img_to_img(data->base_img, data->wall_img, 0, 0); // Copy the background to the base image
        //draw_map(data); // Redraw the walls

        if (data->state < 0 || data->state > 1 || data->direction < 0 || data->direction > 3) {
            printf("render_next_frame: invalid state or direction\n");
            return (1);
        }

        void **frames = (data->state == 0) ? (void **)data->idle_frames[data->direction] : (void **)data->running_frames[data->direction];
        if (frames == NULL || frames[data->current_frame] == NULL) {
            printf("render_next_frame: frames or frames[current_frame] is NULL\n");
            return (1);
        }
		t_img img = load_image(data->mlx, data->idle_frames[data->direction][data->current_frame]);
        put_img_to_img(data->base_img, img, img.w, img.y); // Copy the character frame to the base image

        mlx_put_image_to_window(data->mlx, data->win, data->base_img.img_ptr, 0, 0); // Display the base image

        data->current_frame = (data->current_frame + 1) % 8;
        data->loop_counter = 0;
    }
    return (0);
}

int handle_key_press(int keycode, t_data *data) {
    if (keycode == KEY_ESC) { // Escape key to exit
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    } else if (keycode == KEY_LEFT) { // Left arrow key
        data->direction = 1;
        data->state = 1; // Running
    } else if (keycode == KEY_RIGHT) { // Right arrow key
        data->direction = 2;
        data->state = 1; // Running
    } else if (keycode == KEY_UP) { // Up arrow key
        data->direction = 3;
        data->state = 1; // Running
    } else if (keycode == KEY_DOWN) { // Down arrow key
        data->direction = 0;
        data->state = 1; // Running
    }
    return (0);
}

int handle_key_release(int keycode, t_data *data) {
    if (keycode >= KEY_LEFT && keycode <= KEY_DOWN) // Arrow keys
        data->state = 0;
    return (0);
}

int handle_exit(t_data *data) {
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}
