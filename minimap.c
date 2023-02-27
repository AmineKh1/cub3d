/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:33 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/27 18:32:47 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

        renderRectangle(cub, i * cub->wall_strip_width, (cub->window_height / 2) - (wallStripHeight / 2), cub->wall_strip_width, wallStripHeight, cub->rayc[i].hitdir, i);
        i++;
    }
}

void renderRectangle(t_cub *cub, int x, int y, int w, int h, int hit, int ri) {
    int  j, n;
    int i;
    int b;
    i = x;
    int hitx, hity;
    hitx = round(cub->rayc[ri].hitx);
    hity = round(cub->rayc[ri].hity);

    if (hit == 3 || hit == 0)
        i = hitx % 64;
    else if(hit == 1 || hit == 2)
        i = hity % 64;
    else
        i = -1;
    b = j;
    for (j = y; j < y + h; j++) {
            n = (j - y) * (float)64 / h;
            if (i == -1) {
                my_mlx_pixel_put(cub, x, j, 0x000000);
            }
            else
            my_mlx_pixel_put(cub, x, j, my_mlx_color(cub, i, n, hit));
            
        }
    }
