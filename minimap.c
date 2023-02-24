/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:33 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/23 22:10:40 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void key_press(t_cub *cub, int codekey) {
    double angle = cub->player.rotationangle * M_PI / 180;
    double move_speed = cub->player.movespeed;
    double x_move = 0;
    double y_move = 0;

    if (codekey == 0) { // a
        x_move = cos(angle - M_PI_2);
        y_move = sin(angle - M_PI_2);
    }
    else if (codekey == 2) { // d
        x_move = cos(angle + M_PI_2);
        y_move = sin(angle + M_PI_2);
    }
    else if (codekey == 1) { // s
        x_move = -cos(angle);
        y_move = -sin(angle);
    }
    else if (codekey == 13) { // w
        x_move = cos(angle);
        y_move = sin(angle);
    }
    else if (codekey == 124) { // arrow right
        cub->player.rotationangle += 5;
        if (cub->player.rotationangle > 360)
            cub->player.rotationangle = 0;
    }
    else if (codekey == 123) { // arrow left
        cub->player.rotationangle -= 5;
        if (cub->player.rotationangle < 0)
            cub->player.rotationangle = 360;
    }
    else if (codekey == 53) { // esc
        exit(0);
    }
    x_move = cub->player.x + (move_speed * x_move);
    y_move = cub->player.y + (move_speed * y_move);
    if(haswallplayer(x_move, y_move, cub) == 0)
        return ;
    cub->player.x = round(x_move);
    cub->player.y = round(y_move);
}

void update_map(t_cub *cub, int codekey) {
	key_press(cub, codekey);
}

void renderciel(t_cub *cub) {
    int i;
    int j;

    i = 0;
    while(i < cub->window_height / 2) {
        j = 0;
        while(j < cub->window_width) {
            my_mlx_pixel_put(cub, j, i, cub->C);
            j++;
        }
        i++;
    }
    i = cub->window_height / 2;
    j = 0;
        while(i < cub->window_height) {
        j = 0;
        while(j < cub->window_width) {
            my_mlx_pixel_put(cub, j, i, cub->F);
            j++;
        }
        i++;
    }
}

void render3d(t_cub *cub) {
    int i = 0;
    double distanceProjPlane = ((cub->window_width / 2) / tan(cub->fov_angle / 2));
    double wallStripHeight = 0;
    double d;
    double r = 0;
    int color;
    int g;
    while(i < cub->num_rays) {
        if(cub->rayc[i].distance > 0)
            wallStripHeight = (cub->cubpx / (cub->rayc[i].distance * cos((cub->rayc[i].rayangle - cub->player.rotationangle* M_PI / 180)))) * distanceProjPlane;

        if (r > cub->rayc[i].distance || i == 0)
            r = cub->rayc[i].distance;
        d = 50 / cub->rayc[i].distance;
        if(d > 1)
            d = 1;
            g = cub->rayc[i].hitdir == 1 ? create_trgb(1, 255 *d , 0, 0) : cub->rayc[i].hitdir == 2 ? color = create_trgb(1, 0, 255*d, 0) : cub->rayc[i].hitdir == 3 ? create_trgb(1, 0, 0, 255*d) : cub->rayc[i].hitdir == 0  ? create_trgb(1, 255*d, 255*d, 0): create_trgb(1, 0*d, 0*d, 0*d);
                color = g;
        
        renderRectangle(cub, i * cub->wall_strip_width, (cub->window_height / 2) - (wallStripHeight / 2), cub->wall_strip_width, wallStripHeight, color);
        i++;
    }
}

void renderRectangle(t_cub *cub, int x, int y, int w, int h, int color) {
    int i, j;
    for (i = x; i < x + w; i++) {
        for (j = y; j < y + h; j++) {

            my_mlx_pixel_put(cub, i, j, color);
        }
    }
}
