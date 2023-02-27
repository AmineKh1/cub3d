/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:25:58 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/27 20:55:11 by akhouya          ###   ########.fr       */
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
    // else
    //     return;
    x_move = cub->player.x + (move_speed * x_move);
    y_move = cub->player.y + (move_speed * y_move);
    //print variables
    // printf("x_move: %f  y_move: %f angle: %f cos: %f  sin: %f cub->player.x: %f  cub->player.y: %f\n", x_move, y_move, angle, cos(angle), sin(angle), cub->player.x, cub->player.y);
    if(haswallplayer(x_move, y_move, cub) == 0)
        return ;
    cub->player.x = round(x_move);
    cub->player.y = round(y_move);
}
// void	key_press_move(t_cub *cub, int codekey)
// {
// 	int	angle;

// 	angle = cub->player.rotationangle * M_PI / 180;
// 	if (codekey == 0)
// 	{
// 		cub->x_move = cos(angle - M_PI_2);
// 		cub->y_move = sin(angle - M_PI_2);
// 	}
// 	else if (codekey == 2)
// 	{
// 		cub->x_move = cos(angle + M_PI_2);
// 		cub->y_move = sin(angle + M_PI_2);
// 	}
// 	else if (codekey == 1)
// 	{
// 		cub->x_move = -1 * cos(angle);
// 		cub->y_move = -1 * sin(angle);
// 	}
// 	else if (codekey == 13)
// 	{
// 		cub->x_move = cos(angle);
// 		cub->y_move = sin(angle);
// 	}
// 	else if (codekey == 53)
// 		exit(0);
// }

// void	key_press_angle(t_cub *cub, int codekey)
// {
// 	if (codekey == 123)
// 	{
// 		cub->player.rotationangle -= 5;
// 		if (cub->player.rotationangle < 0)
// 			cub->player.rotationangle = 360;
// 	}
// 	else if (codekey == 124)
// 	{
// 		cub->player.rotationangle += 5;
// 		if (cub->player.rotationangle > 360)
// 			cub->player.rotationangle = 0;
// 	}
// }

// void	key_press(t_cub *cub, int codekey)
// {
// 	double	angle;

// 	angle = cub->player.rotationangle * M_PI / 180;
// 	cub->x_move = 0;
// 	cub->y_move = 0;
// 	key_press_move(cub, codekey);
// 	key_press_angle(cub, codekey);
// 	cub->x_move = cub->player.x + (cub->player.movespeed * cub->x_move);
// 	cub->y_move = cub->player.y + (cub->player.movespeed * cub->y_move);
// 	if (haswallplayer(cub->x_move, cub->y_move, cub) == 0)
// 		return ;
// 	cub->player.x = round(cub->x_move);
// 	cub->player.y = round(cub->y_move);
// }

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
