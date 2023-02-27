/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:38:27 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/27 09:13:45 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#define BUFFER_SIZE 100

static char	*extract_line(char **saved)
{
	char	*buffer;
	char	*holder;
	int		i;

	i = 0;
	while ((*saved)[i] != '\n' && (*saved)[i] != '\0')
		i++;
	buffer = ft_substr(*saved, 0, ++i);
	if ((*saved)[i - 1] == '\0')
		i--;
	if (*buffer == '\0')
	{
		free(*saved);
		*saved = NULL;
		return (buffer);
	}
	holder = ft_strdup(&(*saved)[i]);
	free(*saved);
	*saved = holder;
	return (buffer);
}

static int	read_buffer(int fd, char **saved)
{
	char	*buffer;
	char	*holder;
	int		wrr;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	wrr = read(fd, buffer, BUFFER_SIZE);
	if (wrr < 0)
	{
		free(buffer);
		return (wrr);
	}
	buffer[wrr] = '\0';
	holder = ft_strjoin(*saved, buffer);
	free(*saved);
	*saved = holder;
	free(buffer);
	return (wrr);
}

static char	*get_line(int fd, char **saved)
{
	char	*holder;
	int		wrr;

	while (ft_strchr(*saved, '\n') == NULL)
	{
		wrr = read_buffer(fd, saved);
		if (wrr < 0)
		{
			free(*saved);
			return (NULL);
		}
		if (wrr == 0 && (*saved)[0] != '\0')
		{
			holder = ft_strdup(*saved);
			free(*saved);
			*saved = NULL;
			return (holder);
		}
		else if (wrr == 0 && (*saved)[0] == '\0')
		{
			free(*saved);
			return (NULL);
		}
	}
	return (*saved);
}

char	*get_next_line(int fd)
{
	static char	*saved = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (saved == NULL)
		saved = ft_strdup("");
	saved = get_line(fd, &saved);
	if (saved == NULL)
		return (NULL);
	return (extract_line(&saved));
}
