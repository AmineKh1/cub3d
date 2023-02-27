/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:03:53 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/27 09:48:24 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*advance_whitespace(char *line)
{
	while (ft_isspace(*line))
		line++;
	return (line);
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	free_array_string(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	longest_line(char **array)
{
	int	i;
	int	len;
	int	max;

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
