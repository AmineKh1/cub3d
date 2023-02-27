/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:47:43 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/27 10:43:28 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	**read_file(char *file_name)
{
	int		fd;
	char	*line;
	char	*file;
	char	*tmp;
	char	**lines;

	fd = check_file(file_name);
	if (fd == -1)
		exit(1);
	file = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = file;
		file = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	close(fd);
	lines = ft_split(file, '\n');
	free(file);
	return (lines);
}

int	check_file(char *file_name)
{
	int	fd;

	if (ft_strlen(file_name) < 5)
	{
		printf("Error: invalid file name\n");
		return (-1);
	}
	if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".cub", 4) != 0)
	{
		printf("Error: invalid file name\n");
		return (-1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: invalid file name\n");
		return (-1);
	}
	return (fd);
}

int	get_index_of_map(char **lines)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (lines[i])
	{
		if (count == 6)
			break ;
		if (!empty_line(lines[i]))
			count++;
		i++;
	}
	return (i);
}
