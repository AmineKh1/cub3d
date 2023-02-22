/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:08:28 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/22 16:39:46 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "mlx.h"
# include <stdarg.h>
#include <math.h>

#define LINES 14
#define ROWS 37
#define CUBPX 32
#define WINDOW_WIDTH (ROWS * CUBPX)
#define WINDOWS_HEIGHT (LINES * CUBPX)
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
    void    *img_ptr;
    int    *data;
    t_rayc   *rayc;
    t_player player;
    
}   t_cub;
char	*ft_strdup(char *s);
size_t	ft_strlen(const char *s);
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
#endif