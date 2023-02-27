/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:22:32 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/27 19:14:59 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



void castAllRays(t_cub *cub) {
    double rayangle = (cub->player.rotationangle * M_PI / 180) - (cub->fov_angle / 2);
    int i = 0;
    
    while (i < cub->num_rays) {
        
        rayangle += (cub->fov_angle) / cub->num_rays;
        cub->rayc[i].rayangle = rayangle;
        renderRay(cub, rayangle, i);
        i++;
    }
    
   
}

double distanceBetweenPoints(x1, y1, x2, y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int haswall(int x, int y, t_cub *cub, int i) {
    if(x < 0 || x > (cub->cubpx * cub->row) || y < 0 || y > (cub->cubpx * cub->line))
        return 0;
    int indx = floor(x / cub->cubpx);
    int indy = floor(y / cub->cubpx);
    if (cub->map[indy][indx] == '1') {
    int x_grid = floor(x / cub->cubpx) * cub->cubpx;
    int y_grid = floor(y / cub->cubpx) * cub->cubpx;

    double dist_x = abs(x - x_grid);
    double dist_y = abs(y - y_grid);

    if (dist_x < dist_y){
        if (x > x_grid) {
            cub->rayc[i].hitdir = 0;
        } 
         else {
            cub->rayc[i].hitdir = 2;
            }

    } else {
        if (y > y_grid) {
            cub->rayc[i].hitdir = 1;
        } else {
            cub->rayc[i].hitdir = 3;
        }
    
    }
    
    if(i > 0 && ((dist_x == cub->cubpx - 1 && dist_y == 0) || (dist_x == 0 && dist_y == cub->cubpx - 1) || (dist_x == cub->cubpx -1 && dist_y == cub->cubpx - 1 ) || (dist_x == 0 && dist_y == 0)))
    {
        if(i > 0)
        cub->rayc[i].hitdir = 4;
    }
    return 0;
    }
    return 1;
}
