/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:32:12 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/28 19:17:36 by heloufra         ###   ########.fr       */
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
	printf("Error missing texture\n");
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
	cub->texture = malloc(sizeof(t_texture) * 4);
	if (!cub->texture)
		return (0);
	cub->texture[0].img = mlx_xpm_file_to_image(cub->mlx, cub->no,
			&cub->texture[0].width, &cub->texture[0].height);
	cub->texture[1].img = mlx_xpm_file_to_image(cub->mlx, cub->we,
			&cub->texture[1].width, &cub->texture[1].height);
	cub->texture[2].img = mlx_xpm_file_to_image(cub->mlx, cub->ea,
			&cub->texture[2].width, &cub->texture[2].height);
	cub->texture[3].img = mlx_xpm_file_to_image(cub->mlx, cub->so,
			&cub->texture[3].width, &cub->texture[3].height);
	if (cub->texture->img == NULL || cub->texture[1].img == NULL
		|| cub->texture[2].img == NULL || cub->texture[3].img == NULL)
		return (0);
	return (set_textures_get_data(cub));
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
		printf("Error: invalid texture\n");
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
