/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:02:18 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/24 03:34:01 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parser(t_cub *cub, char *file)
{
	char **lines;
	
	lines = read_file(file);
	if (!lines)
		return 0;
	if (verify_file(lines) == 0)
	{
		free_array_string(lines);
		return 0;
	}
	cub->C = -1;
	cub->F = -1;
	if (parser_texture(cub, lines) == 0 || parser_color(cub, lines) == 0 || parser_map(cub, lines) == 0)
	{
		free_array_string(lines);
		return 0;
	}
	t_cub_init(cub);
	free_array_string(lines);
	return (1);
}
