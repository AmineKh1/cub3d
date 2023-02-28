/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 02:40:14 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/28 18:05:16 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	parser_map(t_cub *cub, char **lines)
{
	int	i;

	i = get_index_of_map(lines);
	get_map(cub, &lines[i]);
	if (cub->map == NULL)
	{
		printf("Error Map not found\n");
		return (0);
	}
	if (valid_map(cub) && valid_player(cub) && valid_map_lines(cub))
		return (1);
	return (0);
}

int	is_map(char *line)
{
	advance_whitespace(line);
	if (*line == '1')
		return (1);
	return (0);
}

int	get_map(t_cub *cub, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (line[len])
		len++;
	cub->map = ft_calloc(len + 1, sizeof(char *));
	i = 0;
	while (line[i])
	{
		cub->map[i] = ft_strdup(line[i]);
		i++;
	}
	return (1);
}

int	valid_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (ft_strchr("0NSEW", cub->map[i][j]))
			{
				if (valid_map_space(cub, i, j) == 0)
				{
					printf("Error invalid map\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_map_space(t_cub *cub, int i, int j)
{
	int	len;

	len = array_len(cub->map);
	if (j == 0 || i == 0 || i == len - 1 || j == ft_strlen(cub->map[i]) - 1)
		return (0);
	if ((ft_isspace(cub->map[i - 1][j - 1]) || cub->map[i - 1][j - 1] == '\0')
		|| (ft_isspace(cub->map[i - 1][j]) || cub->map[i - 1][j] == '\0')
		|| (ft_isspace(cub->map[i - 1][j + 1])
		|| cub->map[i - 1][j + 1] == '\0')
		|| (ft_isspace(cub->map[i][j - 1]) || cub->map[i][j - 1] == '\0')
		|| (ft_isspace(cub->map[i][j + 1]) || cub->map[i][j + 1] == '\0')
		|| (ft_isspace(cub->map[i + 1][j - 1])
		|| cub->map[i + 1][j - 1] == '\0')
		|| (ft_isspace(cub->map[i + 1][j]) || cub->map[i + 1][j] == '\0')
		|| (ft_isspace(cub->map[i + 1][j + 1])
		|| cub->map[i + 1][j + 1] == '\0'))
	{
		return (0);
	}
	return (1);
}

/*
int main(int argc, char *argv[])
{
    t_cub *cub;
    char **lines;

    if (argc != 2)
        return (0);
    cub = ft_calloc(sizeof(t_cub), 1);
    lines = read_file(argv[1]);
    if (!parser_map(cub, lines))
        return (0);
		
    int i = 0;
    while (cub->map[i])
    {
        printf("%s\n", cub->map[i]);
        i++;
    }
    return (0);
} */