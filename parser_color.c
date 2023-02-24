/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:49:14 by heloufra          #+#    #+#             */
/*   Updated: 2023/02/24 02:39:52 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int parser_color(t_cub *cub, char **lines)
{
    int i;

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

int valid_colors(t_cub *cub)
{
    if (cub->F > 0 && cub->C > 0)
        return (1);
    return (0);
}

char **get_rgb(char *line)
{
    char **colors;
    char *str;
    int    i;
    int   count;

    advance_whitespace(line);
    line++;
    str = remove_spaces(line);
    i = 0;
    count = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != ',')
        {
            free(str);
            printf("Error : Invalid color\n");
            return (NULL);
        }
        if (str[i] == ',')
            count++;
        i++;
    }
    if (count != 2 || str[i - 1] == ',' || str[0] == ',')
    {
        free(str);
        printf("Error : Invalid color\n");
        return (NULL);
    }
    colors = ft_split(str, ',');
       free(str);
    count = 0;
    while (colors[count])
        count++;
    if (count != 3)
    {
        free_array_string(colors);
        printf("Error : Invalid color\n");
        return (NULL);
    }
    return (colors);
}

char *remove_spaces(char *line)
{
    char *str;
    int i;
    int j;

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

int get_color(t_cub *cub, char *line)
{
    char **colors;
    int color;
    int r;
    int g;
    int b;

    colors = get_rgb(line);
    if (!colors)
        return (0);
    r = ft_atoi(colors[0]);
    g = ft_atoi(colors[1]);
    b = ft_atoi(colors[2]);
    if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
        color = r << 16 | g << 8 | b;
    else
    {
        printf("Error : Invalid color\n");
        return (0);
    }
    line = advance_whitespace(line);
    if (line[0] == 'F')
        cub->F = color;
    else if (line[0] == 'C')
        cub->C = color;
    return (1);
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