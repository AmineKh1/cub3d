/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:25:58 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/28 10:27:34 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calculateplayermovement(t_cub *cub, double angle, int keycode)
{
	cub->x_move = 0;
	cub->y_move = 0;
	if (keycode == KEY_A)
	{
		cub->x_move = cos(angle - M_PI_2);
		cub->y_move = sin(angle - M_PI_2);
	}
	else if (keycode == KEY_D)
	{
		cub->x_move = cos(angle + M_PI_2);
		cub->y_move = sin(angle + M_PI_2);
	}
	else if (keycode == KEY_S)
	{
		cub->x_move = -cos(angle);
		cub->y_move = -sin(angle);
	}
	else if (keycode == KEY_W)
	{
		cub->x_move = cos(angle);
		cub->y_move = sin(angle);
	}
}

void	updateplayerposition(t_cub *cub, double angle, int keycode)
{		
	calculateplayermovement(cub, angle, keycode);
	cub->x_move = cub->player.x + (cub->player.movespeed * cub->x_move);
	cub->y_move = cub->player.y + (cub->player.movespeed * cub->y_move);
	if (haswallplayer(cub->x_move, cub->y_move, cub) == 0)
		return ;
	cub->player.x = round(cub->x_move);
	cub->player.y = round(cub->y_move);
}

void	key_press(t_cub *cub, int codekey)
{
	double	angle;

	angle = cub->player.rotationangle * M_PI / 180;
	if (codekey == KEY_ESC)
		exit(0);
	else if (codekey == KEY_RIGHT)
	{
	cub->player.rotationangle += 5;
		if (cub->player.rotationangle > 360)
			cub->player.rotationangle = 0;
	}
	else if (codekey == KEY_LEFT)
	{
		cub->player.rotationangle -= 5;
		if (cub->player.rotationangle < 0)
			cub->player.rotationangle = 360;
	}
	else
		updateplayerposition(cub, angle, codekey);
}

void	update_map(t_cub *cub, int codekey)
{
	key_press(cub, codekey);
}

int	haswallplayer(int x, int y, t_cub *cub)
{
	int	indx;
	int	indy;

	if (x < 0 || x > (cub->cubpx * cub->row)
		|| y < 0 || y > (cub->cubpx * cub->line))
		return (0);
	indx = floor((x + 1) / cub->cubpx);
	indy = floor((y + 1) / cub->cubpx);
	if (cub->map[indy][indx] == '1')
		return (0);
	return (1);
}
