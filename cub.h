/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:08:28 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/24 18:29:49 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H
#include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "mlx.h"
# include <stdarg.h>
#include <math.h>
#include "libft/libft.h"

#define LINES 14
#define ROWS 37
#define CUBPX 32
#define WINDOW_WIDTH 1000
#define WINDOWS_HEIGHT 1000
#define FOV_ANGLE (60 * (M_PI / 180))
#define WALL_STRIP_WIDTH 1
#define NUM_RAYS (WINDOW_WIDTH / WALL_STRIP_WIDTH)
#define MINIMAP 0.2

typedef struct s_rayc {
    double rayangle;
    double hity;
    double hitx;
    double distance;
    int hitdir; // 'E' for east, 'W' for westm 'N' 'north', 'S' 'south'
} t_rayc;

typedef struct s_player {
    double x;
    double y;
    double radius;
    double turnDirection;
    double walkDirection;
    double rotationangle;
    double movespeed;
    double rotationSpeed;
} t_player;

typedef struct s_cub {
    void    *mlx;
    void    *win;
    char    **map;
    char    *SO;
    char    *NO;
    char    *WE;
    char    *EA;
    int     F;
    int     C;
    void    *img_ptr;
    int    *data;
    int     row;
    int     line;
    int cubpx;
    int window_width;
    int window_height;
    double fov_angle;
    int num_rays;
    float minimap;
    int wall_strip_width;
    t_rayc   *rayc;
    t_player player;
    
}   t_cub;


void lineray(t_cub *cub, double angle, int i);
void renderRay(t_cub *cub, double angle, int i);
void castAllRays(t_cub *cub);
double distanceBetweenPoints(int x1, int y1, int x2, int y2);
int	create_trgb(int t, int r, int g, int b);
int haswall(int x, int y, t_cub *cub, int i);
void key_press(t_cub *cub, int codekey);
void update_map(t_cub *cub, int codekey);
void renderRectangle(t_cub *cub, int x, int y, int w, int h, int color) ;
void render3d(t_cub *cub);
void update_map(t_cub *cub, int codekey);
void	my_mlx_pixel_put(t_cub *data, int x, int y, int color);
int haswallplayer(int x, int y, t_cub *cub);
void renderciel(t_cub *cub);

int    parser(t_cub *cub, char *file);
int     verify_file(char **lines);
int     is_color(char *line);
int     is_texture(char *line);
int     parser_map(t_cub *cub, char **lines);
int     parser_texture(t_cub *cub, char **lines);
int     parser_color(t_cub *cub, char **lines);
void    t_cub_init(t_cub *cub);
char    **read_file(char *file_name);
void    free_array_string(char **array);
int     array_len(char **array);
int     longest_line(char **array);
int     empty_line(char *line);
char    *advance_whitespace(char *line);
int	    check_file(char *file_name);
char    *get_next_line(int fd);
int    get_texture(t_cub *cub, char *line);
int    valid_textures(t_cub *cub);
int     get_color(t_cub *cub, char *line);
int     valid_colors(t_cub *cub);
char    *remove_spaces(char *line);
int     valid_map_lines(t_cub *cub);

int     valid_player(t_cub *cub);
int     valid_map_space(t_cub *cub, int i, int j);
int     valid_map(t_cub *cub);
int     get_map(t_cub *cub, char **line);
int     is_map(char *line);


#endif