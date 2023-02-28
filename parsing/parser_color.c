/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:49:14 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/28 19:15:28 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	parser_color(t_cub *cub, char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_color(lines[i]))
			if (!get_color(cub, lines[i]))
				break ;
		i++;
	}
	if (valid_colors(cub))
		return (1);
	printf("Error : Invalid color\n");
	return (0);
}

int	valid_colors(t_cub *cub)
{
	if (cub->f > 0 && cub->c > 0)
		return (1);
	return (0);
}

char	**validate_rgb(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
			break ;
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count == 2 || str[i - 1] != ',' || str[0] != ','
		|| (!ft_isdigit(str[i]) && str[i] != ','))
	{
		return (ft_split(str, ','));
	}
	printf("Error : Invalid color\n");
	return (NULL);
}

char	**get_rgb(char *line)
{
	char	*str;
	char	**colors;

	advance_whitespace(line);
	line++;
	str = remove_spaces(line);
	colors = validate_rgb(str);
	free(str);
	return (colors);
}

char	*remove_spaces(char *line)
{
	char	*str;
	int		i;
	int		j;

	str = ft_strdup(line);
	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			j = i;
			while (str[j])
			{
				str[j] = str[j + 1];
				j++;
			}
			i--;
		}
		i++;
	}
	return (str);
}
