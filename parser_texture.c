/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:32:12 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/24 18:15:24 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int     parser_texture(t_cub *cub, char **lines)
{
    int i;

    i = 0;
    while (lines[i])
    {
        if (is_texture(lines[i]))
            if (!get_texture(cub, lines[i]))
                break ;
        i++;
    }
    if (valid_textures(cub))
        return (1);
    printf("Error missing texture\n");
    return (0);
}

int    get_texture(t_cub *cub, char *line)
{
    char *texture;
    char *path;
    char *tmp;
    int  fd;
    
    line = advance_whitespace(line);
    texture = ft_substr(line, 0, 2);
    tmp = ft_substr(line, 2, ft_strlen(line) - 2);
    path = ft_strtrim(tmp, " \t\v\f\r");
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
            free(tmp); 
            free(texture);
            free(path);
        printf("Error texture file not found\n");
        return (0);
    }
    close(fd);
    free(tmp); 
    if (!ft_strncmp(texture, "NO", 2))
        cub->NO = path;
    else if (!ft_strncmp(texture, "SO", 2))
        cub->SO = path;
    else if (!ft_strncmp(texture, "WE", 2))
        cub->WE = path;
    else
        cub->EA = path;
    free(texture);
    return (1);
}

int    valid_textures(t_cub *cub)
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