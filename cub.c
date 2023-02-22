/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:08:11 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/19 16:01:38 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// const int LINES = 14;
// const int ROWS = 37;
// const int CUBPX  = 32;
// const int WINDOW_WIDTH = ROWS * CUBPX;
// const int WINDOWS_HEIGHT = LINES * CUBPX;
// const double FOV_ANGLE = 60 * (M_PI / 180);
// const int WALL_STRIP_WIDTH = 5;
// const int NUM_RAYS = WINDOW_WIDTH / WALL_STRIP_WIDTH;
// const double MINIMAP = 0.2;


// int haswall(int x, int y, t_cub *cub) {
//     if(x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOWS_HEIGHT)
//         return 0;
//     int indx = floor(x / CUBPX);
//     int indy = floor(y / CUBPX);
//     if (cub->map[indy][indx] == '1')
//         return  0;
//     return 1;
// }
// double distanceBetweenPoints(x1, y1, x2, y2) {
//     return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
// }
// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// void lineray(t_cub *cub, double angle, int i) {
//     int x1 = cub->player.x;
//     int y1 = cub->player.y;
//     int x2 = x1 + cos(angle) * 1000;
//     int y2 = y1 + sin(angle) * 1000;
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1;
//     int err = dx - dy;
//     while (x1 != x2 || y1 != y2) {
//         int e2 = err << 1;
//         if (e2 > -dy) {
//             err -= dy;
//             x1 += sx;
//         }
//         if (e2 < dx) {
//             err += dx;
//             y1 += sy;
//         }
//         //distance beetwen wall
//         cub->rayc[i].hitx = x1;
//         cub->rayc[i].hity = y1;
//         cub->rayc[i].distance = distanceBetweenPoints(cub->player.x,  cub->player.y, x1, y1);
//         if(haswall(x1, y1, cub) == 0)
//         {
//             // printf("%f\n", cub->rayc[i].distance);
//             return ;
//         }
            
//         mlx_pixel_put(cub->mlx, cub->win, MINIMAP * x1 , MINIMAP * y1, create_trgb(1, 136, 8, 8));
        
//     }
// }
// void renderRay(t_cub *cub, double angle, int i) {
//     lineray(cub, angle, i);
// }
// void castAllRays(t_cub *cub) {
//     double rayangle = (cub->player.rotationangle * M_PI / 180) - (FOV_ANGLE / 2);
//     // printf("%f, %f\n", rayangle, cub->player.rotationangle);
//     int i = 0;
    
//     while (i < NUM_RAYS) {
//         rayangle += (FOV_ANGLE) / NUM_RAYS;
//         cub->rayc[i].rayangle = rayangle;
//         renderRay(cub, rayangle, i);
//         i++;
//     }
    
// }


// void draw_pixels(int color, int x, int y, t_cub *cub) {
//     int i = -1;
//     int j = -1;
//     while(++i < CUBPX)
//     {
//         j = -1; 
//         while (++j < CUBPX)
//         {
//             mlx_pixel_put(cub->mlx, cub->win, MINIMAP * (x + i), MINIMAP * (y + j), color);
//         }
//     }
// }
// void draw_circle(int color, t_cub *cub) {
//     int i = 0;
//     int j = 0;
//     double x1;
//     double y1;
//     double angle;
    
//     while (j < cub->player.radius) {
        
//     i = 0;
//     while (i < 360) {
//         angle = i;
//         x1 = j * cos(angle * M_PI / 180);
//         y1 = j * sin(angle * M_PI / 180);
//         mlx_pixel_put(cub->mlx, cub->win, MINIMAP * (cub->player.x + x1), MINIMAP * (cub->player.y + y1), color);
//         i++;
//     }
//     j++;
//     }
// }
// void renderRectangle(t_cub *cub, int x, int y, int w, int h, int color) {
//     int i, j;
//     for (i = x; i < x + w; i++) {
//         for (j = y; j < y + h; j++) {
//             mlx_pixel_put(cub->mlx, cub->win, i, j, color);
//             // cub->data[i][j] = color;
//         }
//     }
// }
// // void renderRectangle(t_cub *cub, int x, int y, int w, int h, int color) {
// //     int bpp = 32;
// //     int size_line = ROWS * LINES * CUBPX;
// //     int endian;
// //     // mlx_destroy_image(cub->mlx, cub->img_ptr);
// //     // cub->img_ptr = mlx_new_image(cub->mlx, ROWS * CUBPX, LINES * CUBPX);
// //     char *img_data = mlx_get_data_addr(cub->img_ptr, &bpp, &size_line, &endian);
// //     int img_width = WINDOW_WIDTH;
// //     int img_height = WINDOWS_HEIGHT;
// //     int x_end = x + w;
// //     int y_end = y + h;
// //     if (x < 0) x = 0;
// //     if (y < 0) y = 0;
// //     if (x_end > img_width) x_end = img_width;
// //     if (y_end > img_height) y_end = img_height;
// //     int img_x, img_y;
// //     for (img_y = y; img_y < y_end; img_y++) {
// //         for (img_x = x; img_x < x_end; img_x++) {
// //             int pixel_offset = (img_y * size_line) + (img_x * (bpp / 8));
// //             *(unsigned int*)(img_data + pixel_offset) = color;
// //         }
// //     }
// //     mlx_put_image_to_window(cub->mlx, cub->win, cub->img_ptr, 0, 0);
// // }
// void render3d(t_cub *cub) {
//     int i = 0;
//     double distanceProjPlane = ((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2));
//     double wallStripHeight = 0;
//     while(i < NUM_RAYS) {
//         wallStripHeight = (CUBPX / cub->rayc[i].distance) * distanceProjPlane;
//         renderRectangle(cub, i * WALL_STRIP_WIDTH, (WINDOWS_HEIGHT / 2) - (wallStripHeight / 2), WALL_STRIP_WIDTH, wallStripHeight, create_trgb(1, 136, 8, 8));
//         i++;
//     }
// }
// void setup_map(t_cub *cub) {
//     cub->mlx = mlx_init();
// 	cub->win = mlx_new_window(cub->mlx,
// 			 WINDOW_WIDTH, WINDOWS_HEIGHT, "cub");
//     cub->player.radius = 4;
//     cub->player.turnDirection = 0;
//     cub->player.movespeed = 5;
//     cub->player.rotationangle = 90;
//     cub->player.rotationSpeed = 5 * (M_PI / 180);
//     cub->player.walkDirection = 0;
//     int i = -1;
//     int j = 0;
//     int endian = 0;
//     int px = CUBPX;
//     int linesize = ROWS * CUBPX * LINES;
//     // cub->img_ptr = mlx_new_image(cub->mlx, ROWS * CUBPX, LINES * CUBPX);
//     // cub->data = mlx_get_data_addr(cub->img_ptr, &CUBPX, &linesize, &endian);
//     while(++i < 14)
//     {
//         j = -1;
//         while(cub->map[i][++j] != '\0')
//         {
//             if(cub->map[i][j] != '\0' && cub->map[i][j] == 'W')
//             {
//                 cub->player.x = j * CUBPX;
//                 cub->player.y = i * CUBPX;
//             }
//         }
//         // cub->data[i] = mlx_get_data_addr(cub->img_ptr, &px, &linesize, &endian);
//     }
// }

        
// void line(t_cub *cub) {
//     double angle = cub->player.rotationangle * M_PI / 180;
//     int x1 = cub->player.x;
//     int y1 = cub->player.y;
//     int x2 = x1 + cos(angle) * 1000;
//     int y2 = y1 + sin(angle) * 1000;
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1;
//     int err = dx - dy;
//     while (x1 != x2 || y1 != y2) {
//         int e2 = err << 1;
//         if (e2 > -dy) {
//             err -= dy;
//             x1 += sx;
//         }
//         if (e2 < dx) {
//             err += dx;
//             y1 += sy;
//         }
//         mlx_pixel_put(cub->mlx, cub->win, MINIMAP * x1 , MINIMAP * y1, create_trgb(1, 240, 248, 255));
//     }
// }
// void key_press(t_cub *cub, int codekey) {
//     double angle = cub->player.rotationangle * M_PI / 180;
//     double move_speed = cub->player.movespeed;
//     double x_move = 0;
//     double y_move = 0;

//     if (codekey == 2) { // d
//         x_move = cos(angle - M_PI_2);
//         y_move = sin(angle - M_PI_2);
//     }
//     else if (codekey == 0) { // a
//         x_move = cos(angle + M_PI_2);
//         y_move = sin(angle + M_PI_2);
//     }
//     else if (codekey == 13) { // w
//         x_move = -cos(angle);
//         y_move = -sin(angle);
//     }
//     else if (codekey == 1) { // s
//         x_move = cos(angle);
//         y_move = sin(angle);
//     }
//     else if (codekey == 124) { // arrow right
//         cub->player.rotationangle += 5;
//         if (cub->player.rotationangle > 360)
//             cub->player.rotationangle = 0;
//     }
//     else if (codekey == 123) { // arrow left
//         cub->player.rotationangle -= 5;
//         if (cub->player.rotationangle < 0)
//             cub->player.rotationangle = 360;
//     }
//     else if (codekey == 53) { // esc
//         exit(0);
//     }
//     x_move = cub->player.x + move_speed * x_move;
//     y_move = cub->player.y + move_speed * y_move;
//     if(haswall(x_move, y_move, cub) == 0)
//         return ;
//     cub->player.x = x_move;
//     cub->player.y = y_move;
// }

// void update_map(t_cub *cub, int codekey) {
// 	key_press(cub, codekey);
// }
// void rander_map(t_cub *cub) {
//     int i = -1;
//     int j = 0;
//     mlx_clear_window(cub->mlx, cub->win);
//     while(++i < 14)
//     {
//         j = -1;
//         while(cub->map[i][++j] != '\0')
//         {
//             if(cub->map[i][j] != '\0' && cub->map[i][j] == '1')
//                 draw_pixels(create_trgb(1, 255, 255, 255), j * CUBPX, i * CUBPX, cub);
//             if(cub->map[i][j] != '\0' && cub->map[i][j] == 'W')
//             {
//                 draw_circle(create_trgb(1, 136, 8, 8), cub);
//                 // line(cub);
//                 castAllRays(cub);
//             }
//             // if(cub->map[i][j] != '\0' && (cub->map[i][j] != ' ' || cub->map[i][j] == '0')) {
//             //     draw_pixels(create_trgb (0, 0, 255, 255), j * CUBPX, i * CUBPX, cub);
//             // }
                
//         }
//     }
// }
// int draw_map(int key ,t_cub *cub) {


//     update_map(cub, key);
//     rander_map(cub);
//     render3d(cub);
//     // mlx_put_image_to_window(cub->mlx, cub->win, cub->img_ptr, ROWS * CUBPX, LINES * CUBPX);
    
//     return 0;
// }
// int main() {

//     t_cub cub;
// 	cub.lent.y = 10;
//     cub.map = (char**)malloc(ROWS * sizeof(char*));
//     cub.map[0] = strdup("111111111111111111111111111111111");
//     cub.map[1] = strdup("111111  1000000000000000000000001");
//     cub.map[2] = strdup("1000011111010000000000000011100011");
//     cub.map[3] = strdup("11000000000100111100100001111111111");
//     cub.map[4] = strdup("100011111111001 1000110000000000111");
//     cub.map[5] = strdup("11111111100000111000000000000111111");
//     cub.map[6] = strdup("1100000000001000000W000001111111");
//     cub.map[7] = strdup(" 11111111111111100000000000000011");
//     cub.map[8] = strdup("1100001        10001000000011111111");
//     cub.map[9] = strdup("11000011111 1111000111100000111111111");
//     cub.map[10] = strdup("10000000001110000001 100000111");
//     cub.map[11] = strdup("11000001111100011111111111011");
//     cub.map[12] = strdup("11111111 1110111 10111ß10100011");
//     cub.map[13] = strdup("         1111111 1111111111111");
//     cub.rayc = malloc(NUM_RAYS * sizeof(t_rayc));

    
	
//     setup_map(&cub);

// 	// rander_map(&cub);
//     // render3d(&cub);
//     // mlx_put_image_to_window(cub.mlx, cub.win, cub.img_ptr, ROWS * CUBPX, LINES * CUBPX);
//     // mlx_hook(cub.win, 2, 0, &draw_map, &cub);
//     int width = 37;
// int height = 14;
// int bpp = 32;  // 32 bits per pixel
// int size_line = width * (bpp / 8);  // number of bytes in a single scanline
// int endian = 0;  // little-endian

// // Create a new image
// void *img_ptr = mlx_new_image(cub.mlx, width, height);

// // Get a pointer to the image data
// char *data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);

// // Now you can manipulate the image data by modifying the 'data' array
// // For example, you can set a pixel at position (x, y) to the color (r, g, b) like this:
// int x = 10;
// int y = 5;
// int r = 255;
// int g = 0;
// int b = 0;
// int pos = (y * size_line) + (x * (bpp / 8));
// data[pos] = b;
// data[pos + 1] = g;
// data[pos + 2] = r;

// // Finally, display the image in a window
// mlx_put_image_to_window(cub.mlx, cub.win, img_ptr, 0, 0);
// 	mlx_loop(cub.mlx);
    
// }
