/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:20:14 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/28 18:47:11 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_cub *data, int x, int y, int color)
{
	if (y > 0 && y < data->window_height && x > 0 && x < data->window_width)
		data->data[y * data->window_width + x] = color;
}

int	my_mlx_color(t_cub *data, int x, int y, int i)
{
	return (*(int *)(data->texture[i].data
		+ (y * data->texture[i].size_line + x * (data->texture[i].bpp / 8))));
}

void	init_setup(t_cub *cub)
{
	int	px;
	int	linesize;
	int	endian;

	endian = 0;
	px = cub->line;
	linesize = 0;
	cub->win = mlx_new_window(cub->mlx,
			cub->window_width, cub->window_height, "cub");
	cub->player.radius = 4;
	cub->player.turn_direction = 0;
	cub->player.movespeed = 5;
	cub->player.rotationangle = 90;
	cub->player.rotation_speed = 3 * (M_PI / 180);
	cub->player.walk_direction = 0;
	cub->img_ptr = mlx_new_image(cub->mlx,
			cub->window_width, cub->window_height);
	cub->data = (int *)mlx_get_data_addr(cub->img_ptr, &px, &linesize, &endian);
}

void	setup_map(t_cub *cub)
{
	int	i;
	int	j;
	int	px;
	int	linesize;
	int	endian;

	i = -1;
	j = 0;
	endian = 0;
	px = cub->line;
	linesize = 0;
	init_setup(cub);
	while (++i < cub->line)
	{
		j = -1;
		while (cub->map[i][++j] != '\0')
		{
			if (ft_strchr("NSEW", cub->map[i][j]))
			{
				cub->player.x = j * cub->cubpx + 16;
				cub->player.y = i * cub->cubpx + 16;
			}
		}
	}
}

void	draw_pixels(int color, int x, int y, t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < cub->cubpx)
	{
		j = -1;
		while (++j < cub->cubpx)
			my_mlx_pixel_put(cub, cub->minimap * (x + i),
				cub->minimap * (y + j), color);
	}
}
