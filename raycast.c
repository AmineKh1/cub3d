/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:22:32 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/22 16:35:36 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
void lineray(t_cub *cub, double angle, int i) {

    int x1 = cub->player.x;
    int y1 = cub->player.y;
    int x2 = x1 + cos(angle) * 1000;
    int y2 = y1 + sin(angle) * 1000;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    while (x1 != x2 || y1 != y2) {
        int e2 = err << 1;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
        //distance beetwen wall
        cub->rayc[i].hitx = x1;
        cub->rayc[i].hity = y1;
        cub->rayc[i].distance = distanceBetweenPoints(cub->player.x,  cub->player.y, x1, y1);
        if(haswall(x1, y1, cub, i) == 0)
        {
            return ;
        }
        
        my_mlx_pixel_put(cub,  (MINIMAP * x1), (MINIMAP * y1), create_trgb(1, 136, 8, 8));
    }
}
void renderRay(t_cub *cub, double angle, int i) {
    lineray(cub, angle, i);
}
void castAllRays(t_cub *cub) {
    double rayangle = (cub->player.rotationangle * M_PI / 180) - (FOV_ANGLE / 2);
    int i = 0;
    
    while (i < NUM_RAYS) {
        rayangle += (FOV_ANGLE) / NUM_RAYS;
        cub->rayc[i].rayangle = rayangle;
        renderRay(cub, rayangle, i);
        i++;
    }
}
double distanceBetweenPoints(x1, y1, x2, y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
#include <stdio.h>
int haswall(int x, int y, t_cub *cub, int i) {
    if(x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOWS_HEIGHT)
        return 0;
   
    int indx = floor(x / CUBPX);
    int indy = floor(y / CUBPX);
    if (cub->map[indy][indx] == '1') {
    int x_grid = floor(x / CUBPX) * CUBPX;
    int y_grid = floor(y / CUBPX) * CUBPX;

    double dist_x = abs(x - x_grid);
    double dist_y = abs(y - y_grid);

    // determine hit direction ussing angle of ray
    if (dist_x < dist_y) {
        if (x > x_grid) {
            cub->rayc[i].hitdir = 0; // east yellow
        } 
         else {
            cub->rayc[i].hitdir = 2; // west  GREEN
            }

    } else {
        if (y > y_grid) {
            cub->rayc[i].hitdir = 1; // north red 
        } else {
            cub->rayc[i].hitdir = 3; // south BLUE
        }
    
    }
    
    if(i > 0 && ((dist_x == 31 && dist_y == 0) || (dist_x == 0 && dist_y == 31) || (dist_x == 31 && dist_y == 31 ) || (dist_x == 0 && dist_y == 0)))
    {
        if(i > 0)
        cub->rayc[i].hitdir = 4;
        
    
    }
    return 0;
    }
    return 1;
}

int haswallplayer(int x, int y, t_cub *cub) {
    if(x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOWS_HEIGHT)
        return 0;
    int indx = floor(x / CUBPX);
    int indy = floor(y / CUBPX);
    if (cub->map[indy][indx] == '1') {
        return 0;
    }
    return 1;
}
