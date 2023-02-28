/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:02:18 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/28 18:01:29 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	parser(t_cub *cub, char *file)
{
	char	**lines;

	lines = read_file(file);
	if (!lines)
		return (0);
	if (verify_file(lines) == 0)
	{
		free_array_string(lines);
		return (0);
	}
	cub->c = -1;
	cub->f = -1;
	if (parser_texture(cub, lines) == 0
		|| parser_color(cub, lines) == 0 || parser_map(cub, lines) == 0)
	{
		free_array_string(lines);
		return (0);
	}
	t_cub_init(cub);
	free_array_string(lines);
	return (1);
}

int	get_color(t_cub *cub, char *line)
{
	char	**colors;
	int		color;
	int		r;
	int		g;
	int		b;

	colors = get_rgb(line);
	if (!colors)
		return (0);
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_array_string(colors);
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
	{
		color = r << 16 | g << 8 | b;
			line = advance_whitespace(line);
		if (line[0] == 'F')
			cub->f = color;
		else if (line[0] == 'C')
			cub->c = color;
		return (1);
	}
	printf("Error : Invalid color\n");
	return (0);
}

int	valid_player(t_cub *cub)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
				|| cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	printf("Error : Invalid player\n");
	return (0);
}

int	valid_map_lines(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (!ft_strchr("10NSEW", cub->map[i][j])
				&& !ft_isspace(cub->map[i][j]))
			{
				printf("Error : Invalid map\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	t_cub_init(t_cub *cub)
{
	cub->line = array_len(cub->map);
	cub->row = longest_line(cub->map);
	cub->window_width = cub->row * 64;
	cub->window_height = cub->line * 64;
	cub->fov_angle = 60 * (M_PI / 180);
	cub->num_rays = cub->window_width / WALL_STRIP_WIDTH;
}
