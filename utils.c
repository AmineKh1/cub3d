/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:03:53 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/24 00:25:42 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char    *advance_whitespace(char *line)
{
	while (ft_isspace(*line))
		line++;
	return (line);
}

int     empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void    free_array_string(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int     array_len(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int     longest_line(char **array)
{
	int i;
	int len;
	int max;

	i = 0;
	max = 0;
	while (array[i])
	{
		len = ft_strlen(array[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

char    **read_file(char *file_name)
{
    int     fd;
    char    *line;
    char    *file;
    char    *tmp;
    char    **lines;

    fd = check_file(file_name);
    if (fd == -1)
        exit(1);
    file = ft_strdup("");
    while ((line = get_next_line(fd)) !=  NULL)
    {
        tmp = file;
        file = ft_strjoin(tmp, line);
        free(line);
        free(tmp);
    }
    close(fd);
    lines = ft_split(file, '\n');
    free(file);
    return (lines);
}

int	check_file(char *file_name)
{
	int fd;

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
	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		printf("Error: invalid file name\n");
		return (-1);
	}
	return (fd);
}
