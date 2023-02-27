/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:32:12 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/27 10:54:44 by heloufra         ###   ########.fr       */
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
		cub->NO = path;
	else if (!ft_strncmp(texture_type, "SO", 2))
		cub->SO = path;
	else if (!ft_strncmp(texture_type, "WE", 2))
		cub->WE = path;
	else if (!ft_strncmp(texture_type, "EA", 2))
		cub->EA = path;
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
	// cub->tex = malloc(sizeof(t_tex) * 4);
	// if (!cub->tex)
	// 	return (0);
	// cub->tex[0].img = mlx_xpm_file_to_image(cub->mlx, cub->NO,
	// 		&cub->tex[0].width, &cub->tex[0].height);
	// cub->tex[1].img = mlx_xpm_file_to_image(cub->mlx,
	// 		cub->SO, &cub->tex[1].width, &cub->tex[1].height);
	// cub->tex[2].img = mlx_xpm_file_to_image(cub->mlx,
	// 		cub->EA, &cub->tex[2].width, &cub->tex[2].height);
	// cub->tex[3].img = mlx_xpm_file_to_image(cub->mlx,
	// 		cub->WE, &cub->tex[3].width, &cub->tex[3].height);
	// if (!cub->tex[0].img || !cub->tex[1].img
	// 	|| !cub->tex[2].img || !cub->tex[3].img)
	// 	return (0);
	// cub->tex[0].data = mlx_get_data_addr(cub->tex[0].img,
	// 		&cub->tex[0].bpp, &cub->tex[0].sl, &cub->tex[0].en);
	// cub->tex[1].data = mlx_get_data_addr(cub->tex[1].img,
	// 		&cub->tex[1].bpp, &cub->tex[1].sl, &cub->tex[1].en);
	// cub->tex[2].data = mlx_get_data_addr(cub->tex[2].img,
	// 		&cub->tex[2].bpp, &cub->tex[2].sl, &cub->tex[2].en);
	// cub->tex[3].data = mlx_get_data_addr(cub->tex[3].img,
	// 		&cub->tex[3].bpp, &cub->tex[3].sl, &cub->tex[3].en);
			

	// cub->texture = malloc(sizeof(t_texture) * 4);

    // cub->texture[0].img = mlx_xpm_file_to_image(cub->mlx, "textures/Stoneflag.xpm", &cub->texture[0].width, &cub->texture[0].height);
    // cub->texture[0].data = mlx_get_data_addr(cub->texture[0].img, &cub->texture[0].bpp, &cub->texture[0].size_line, &cub->texture[0].endian);
    // cub->texture[1].img = mlx_xpm_file_to_image(cub->mlx, "textures/StoneHitler.xpm", &cub->texture[1].width, &cub->texture[1].height);
    // cub->texture[1].data = mlx_get_data_addr(cub->texture[1].img, &cub->texture[1].bpp, &cub->texture[1].size_line, &cub->texture[1].endian);
    // cub->texture[2].img = mlx_xpm_file_to_image(cub->mlx, "textures/Blue.xpm", &cub->texture[2].width, &cub->texture[2].height);
    // cub->texture[2].data = mlx_get_data_addr(cub->texture[2].img, &cub->texture[2].bpp, &cub->texture[2].size_line, &cub->texture[2].endian);
    // cub->texture[3].img = mlx_xpm_file_to_image(cub->mlx, "textures/wall.xpm", &cub->texture[3].width, &cub->texture[3].height);
    // cub->texture[3].data = mlx_get_data_addr(cub->texture[3].img, &cub->texture[3].bpp, &cub->texture[3].size_line, &cub->texture[3].endian);
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
	if (fd < 0)
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
	if (cub->NO && cub->SO && cub->WE && cub->EA)
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