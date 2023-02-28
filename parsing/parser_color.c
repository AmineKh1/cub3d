/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:49:14 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/28 18:02:10 by heloufra         ###   ########.fr       */
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

/*
int main(int argc, char *argv[])
{
	t_cub *cub;
	char **lines;

	if (argc != 2)
		return (0);
	cub = ft_calloc(1, sizeof(t_cub));
	cub->F = -1;
	cub->C = -1;
	lines = read_file(argv[1]);
	int re = parser_color(cub, lines);
	printf("F = %x\n", cub->F);
	printf("C = %x\n", cub->C);
	printf("re = %d\n", re);
}
*/