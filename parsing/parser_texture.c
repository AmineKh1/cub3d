/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:32:12 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/28 18:05:46 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	parser_texture(t_cub *cub, char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_texture(lines[i]))
			if (!get_texture(cub, lines[i]))
				break ;
		i++;
	}
	if (valid_textures(cub) && set_textures(cub))
		return (1);
	printf("Error missing tex\n");
	return (0);
}

int	set_texture(t_cub *cub, char *path, char *texture_type)
{
	if (!ft_strncmp(texture_type, "NO", 2))
		cub->no = path;
	else if (!ft_strncmp(texture_type, "SO", 2))
		cub->so = path;
	else if (!ft_strncmp(texture_type, "WE", 2))
		cub->we = path;
	else if (!ft_strncmp(texture_type, "EA", 2))
		cub->ea = path;
	else
	{
		free(texture_type);
		free(path);
		return (0);
	}
	free(texture_type);
	return (1);
}

int	set_textures(t_cub *cub)
{
	(void)cub;
	return (1);
}

int	get_texture(t_cub *cub, char *line)
{
	char	*tex;
	char	*path;
	char	*tmp;
	int		fd;

	line = advance_whitespace(line);
	tex = ft_substr(line, 0, 2);
	tmp = ft_substr(line, 2, ft_strlen(line) - 2);
	path = ft_strtrim(tmp, " \t\v\f\r");
	fd = open(path, O_RDONLY);
	if (fd < 0 || ft_strncmp(".xpm", &path[ft_strlen(path) - 4], 4))
	{
		free(tmp);
		free(tex);
		free(path);
		printf("Error tex file not found\n");
		return (0);
	}
	close(fd);
	free(tmp);
	return (set_texture(cub, path, tex));
}

int	valid_textures(t_cub *cub)
{
	if (cub->no && cub->so && cub->we && cub->ea)
		return (1);
	return (0);
}

/*
int main(int argc, char **argv)
{
	t_cub *cub;
	char **lines;
	int     ret;
	
	if (argc != 2)
		return (0);
	cub = ft_calloc(1, sizeof(t_cub));
	lines = read_file(argv[1]);
	ret = parser_texture(cub, lines);
	printf("ret = %d\n", ret);
	return (0);
} */