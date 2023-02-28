/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:14:42 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/28 18:04:34 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_variablelineray(t_cub *cub, t_line *line, double angle)
{
	line->x1 = cub->player.x;
	line->y1 = cub->player.y;
	line->x2 = line->x1 + cos(angle) * 10000;
	line->y2 = line->y1 + sin(angle) * 10000;
	line->dx = abs(line->x2 - line->x1);
	line->dy = abs(line->y2 - line->y1);
	if (line->x1 < line->x2)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->y1 < line->y2)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
}

void	lineray(t_cub *cub, double angle, int i)
{
	t_line	line;

	init_variablelineray(cub, &line, angle);
	while (line.x1 != line.x2 || line.y1 != line.y2)
	{
		line.e2 = line.err << 1;
		if (line.e2 > -line.dy)
		{
			line.err -= line.dy;
			line.x1 += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			line.y1 += line.sy;
		}
		cub->rayc[i].hitx = line.x1;
		cub->rayc[i].hity = line.y1;
		cub->rayc[i].distance = distancebetweenpoints(cub->player.x,
				cub->player.y, line.x1, line.y1);
		if (haswall(line.x1, line.y1, cub, i) == 0)
			return ;
		my_mlx_pixel_put(cub, (cub->minimap * line.x1),
			(cub->minimap * line.y1), create_trgb(1, 136, 8, 8));
	}
}

void	renderray(t_cub *cub, double angle, int i)
{
	lineray(cub, angle, i);
}

void	castallrays(t_cub *cub)
{
	double	rayangle;
	int		i;

	i = 0;
	rayangle = (cub->player.rotationangle * M_PI / 180) - (cub->fov_angle / 2);
	while (i < cub->num_rays)
	{
		rayangle += (cub->fov_angle) / cub->num_rays;
		cub->rayc[i].rayangle = rayangle;
		renderray(cub, rayangle, i);
		i++;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
