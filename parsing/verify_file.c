/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:04:17 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/28 19:17:57 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	verify_file(char **lines)
{
	int	i;
	int	color;
	int	texture;

	i = 0;
	color = 0;
	texture = 0;
	while (lines[i])
	{
		if (is_color(lines[i]))
			color++;
		else if (is_texture(lines[i]))
			texture++;
		else if (!empty_line(lines[i]))
			break ;
		i++;
	}
	if (color == 2 && texture == 4)
		return (1);
	printf("Error File's structure is not valid\n");
	return (0);
}

int	is_color(char *line)
{
	line = advance_whitespace(line);
	if ((line[0] == 'F' || line[0] == 'C') && ft_isspace(line[1]))
		return (1);
	return (0);
}

int	is_texture(char *line)
{
	line = advance_whitespace(line);
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		return (1);
	return (0);
}
