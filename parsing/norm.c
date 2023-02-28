/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:35:18 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/28 18:49:13 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	set_textures_get_data(t_cub *cub)
{
	cub->texture[0].data = mlx_get_data_addr(cub->texture[0].img,
			&cub->texture[0].bpp, &cub->texture[0].size_line,
			&cub->texture[0].endian);
	cub->texture[1].data = mlx_get_data_addr(cub->texture[1].img,
			&cub->texture[1].bpp, &cub->texture[1].size_line,
			&cub->texture[1].endian);
	cub->texture[2].data = mlx_get_data_addr(cub->texture[2].img,
			&cub->texture[2].bpp, &cub->texture[2].size_line,
			&cub->texture[2].endian);
	cub->texture[3].data = mlx_get_data_addr(cub->texture[3].img,
			&cub->texture[3].bpp, &cub->texture[3].size_line,
			&cub->texture[3].endian);
	return (1);
}
