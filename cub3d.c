/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:16:33 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/28 18:46:57 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_circle(int color, t_cub *cub)
{
	int		i;
	int		j;
	double	x1;
	double	y1;
	double	angle;

	i = 0;
	j = 0;
	while (j < cub->player.radius)
	{
		i = 0;
		while (i < 360)
		{
			angle = i;
			x1 = j * cos(angle * M_PI / 180);
			y1 = j * sin(angle * M_PI / 180);
			my_mlx_pixel_put(cub, (cub->minimap * (cub->player.x + x1)),
				(cub->minimap * (cub->player.y + y1)), color);
			i++;
		}
		j++;
	}
}

void	render_map_loop(t_cub *cub, int i, int j)
{
	while (++i < cub->line)
	{
		j = -1;
		while (cub->map[i][++j] != '\0')
		{
			if (cub->map[i][j] == '1')
				draw_pixels(create_trgb(1, 255, 255, 255),
					j * cub->cubpx, i * cub->cubpx, cub);
			if (cub->map[i][j] == 'W' || cub->map[i][j] == 'E'
				|| cub->map[i][j] == 'N' || cub->map[i][j] == 'S')
			{
				draw_circle(create_trgb(1, 136, 8, 8), cub);
				castallrays(cub);
			}
		}
	}
}

void	rander_map(t_cub *cub)
{
	int	i;
	int	j;
	int	endian;
	int	px;
	int	linesize;

	i = -1;
	j = 0;
	endian = 0;
	px = cub->line;
	linesize = 0;
	mlx_destroy_image(cub->mlx, cub->img_ptr);
	cub->img_ptr = mlx_new_image(cub->mlx,
			cub->window_width, cub->window_height);
	cub->data = (int *)mlx_get_data_addr(cub->img_ptr, &px, &linesize, &endian);
	render_map_loop(cub, i, j);
	renderciel(cub);
	render3d(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img_ptr, 0, 0);
}

int	draw_map(int key, t_cub *cub)
{
	update_map(cub, key);
	rander_map(cub);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub	*cub;

	cub = ft_calloc(1, sizeof(t_cub));
	if (!cub || argc != 2)
		return (1);
	cub->mlx = mlx_init();
	if (!parser(cub, argv[1]))
		return (1);
	cub->minimap = 0.2;
	cub->wall_strip_width = 1;
	cub->window_height = 1080;
	cub->window_width = 1080;
	cub->cubpx = 64;
	cub->num_rays = cub->window_width / cub->wall_strip_width;
	cub->rayc = malloc(cub->num_rays * sizeof(t_rayc));
	cub->fov_angle = (60 * (M_PI / 180));
	setup_map(cub);
	rander_map(cub);
	mlx_hook(cub->win, 2, 0, &draw_map, cub);
	mlx_loop(cub->mlx);
	return (0);
}
