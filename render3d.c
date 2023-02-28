/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:33 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/28 18:00:49 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	renderciel(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->window_height / 2)
	{
		j = -1;
		while (++j < cub->window_width)
			my_mlx_pixel_put(cub, j, i, cub->c);
	}
	i = cub->window_height / 2;
	while (i < cub->window_height)
	{
		j = -1;
		while (++j < cub->window_width)
			my_mlx_pixel_put(cub, j, i, cub->f);
		i++;
	}
}

void	render3d(t_cub *cub)
{
	int					i;
	double				distanceprojplane;
	double				wallstripheight;
	t_renderrctengle	rectr;

	i = 0;
	distanceprojplane = ((cub->window_width / 2) / tan(cub->fov_angle / 2));
	wallstripheight = 0;
	while (i < cub->num_rays)
	{
		if (cub->rayc[i].distance > 0)
			wallstripheight = (cub->cubpx / (cub->rayc[i].distance
						* cos((cub->rayc[i].rayangle - cub->player.rotationangle
								* M_PI / 180)))) * distanceprojplane;
		rectr.x = i * cub->wall_strip_width;
		rectr.y = (cub->window_height / 2) - (wallstripheight / 2);
		rectr.w = cub->wall_strip_width;
		rectr.h = wallstripheight;
		rectr.hit = cub->rayc[i].hitdir;
		rectr.ri = i;
		renderrectangle(cub, rectr);
		i++;
	}
}

void	renderrectangle(t_cub *cub, t_renderrctengle rectr)
{
	int	j;
	int	n;
	int	i;
	int	hitx;
	int	hity;

	j = rectr.y;
	hitx = round(cub->rayc[rectr.ri].hitx);
	hity = round(cub->rayc[rectr.ri].hity);
	if (rectr.hit == 3 || rectr.hit == 0)
		i = hitx % 64;
	else if (rectr.hit == 1 || rectr.hit == 2)
		i = hity % 64;
	else
		i = -1;
	while (j < rectr.y + rectr.h)
	{
		n = (j - rectr.y) * (float)64 / rectr.h;
		if (i == -1)
			my_mlx_pixel_put(cub, rectr.x, j, 0x000000);
		else
			my_mlx_pixel_put(cub, rectr.x, j,
				my_mlx_color(cub, i, n, rectr.hit));
		j++;
	}
}
