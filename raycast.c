/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:22:32 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/28 11:11:25 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	distancebetweenpoints(x1, y1, x2, y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int	is_corner(double dist_x, double dist_y, int cubpx)
{
	return ((dist_x == 0 && dist_y == 0)
		|| (dist_x == 0 && dist_y == cubpx - 1)
		|| (dist_x == cubpx - 1 && dist_y == 0)
		|| (dist_x == cubpx - 1 && dist_y == cubpx - 1));
}

int	check_bounds(int x, int y, t_cub *cub)
{
	if (x < 0 || x > (cub->cubpx * cub->row)
		|| y < 0 || y > (cub->cubpx * cub->line))
		return (1);
	cub->indx = floor(x / cub->cubpx);
	cub->indy = floor(y / cub->cubpx);
	return (0);
}

void	init_haswall(t_cub *cub, int x, int y)
{
	cub->x_grid = floor(x / cub->cubpx) * cub->cubpx;
	cub->y_grid = floor(y / cub->cubpx) * cub->cubpx;
	cub->dist_x = abs(x - cub->x_grid);
	cub->dist_y = abs(y - cub->y_grid);
}

int	haswall(int x, int y, t_cub *cub, int i)
{
	if (check_bounds(x, y, cub) == 1)
		return (0);
	if (cub->map[cub->indy][cub->indx] == '1')
	{
		init_haswall(cub, x, y);
		if (cub->dist_x < cub->dist_y)
		{
			if (x > cub->x_grid)
				cub->rayc[i].hitdir = 0;
			else
				cub->rayc[i].hitdir = 2;
		}
		else
		{
			if (y > cub->y_grid)
				cub->rayc[i].hitdir = 1;
			else
				cub->rayc[i].hitdir = 3;
		}
		if (i > 0 && is_corner(cub->dist_x, cub->dist_y, cub->cubpx))
			cub->rayc[i].hitdir = 4;
		return (0);
	}
	return (1);
}
