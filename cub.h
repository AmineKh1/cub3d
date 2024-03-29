/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:08:28 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/28 18:38:31 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "mlx.h"
# include <stdarg.h>
# include <math.h>
# include "libft/libft.h"
# define CUBPX 32
# define WALL_STRIP_WIDTH 1
# define MINIMAP 0.2
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define KEY_RIGHT 124
# define KEY_LEFT 123

typedef struct s_rayc
{
	double	rayangle;
	double	hity;
	double	hitx;
	double	distance;
	int		hitdir;
}	t_rayc;

typedef struct s_line {
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_line;

typedef struct s_player {
	double	x;
	double	y;
	double	radius;
	double	turn_direction;
	double	walk_direction;
	double	rotationangle;
	double	movespeed;
	double	rotation_speed;
}	t_player;

typedef struct s_texture {
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		size_line;
	int		bpp;
	int		endian;
}	t_texture;

typedef struct s_renderrctengle {
	int	x;
	int	y;
	int	w;
	int	h;
	int	hit;
	int	ri;
}	t_renderrctengle;

typedef struct s_cub {
	char		*adress;
	int			sz;
	int			bts;
	int			ind;
	double		x_move;
	double		y_move;
	int			indx;
	int			indy;
	double		dist_x;
	double		dist_y;
	int			x_grid;
	int			y_grid;
	void		*imagewall;
	void		*mlx;
	void		*win;
	char		**map;
	char		*so;
	char		*no;
	char		*we;
	char		*ea;
	int			f;
	int			c;
	void		*img_ptr;
	int			*data;
	int			row;
	int			line;
	int			cubpx;
	int			window_width;
	int			window_height;
	double		fov_angle;
	int			num_rays;
	float		minimap;
	int			wall_strip_width;
	t_rayc		*rayc;
	t_player	player;
	t_texture	*texture;
}	t_cub;

void	lineray(t_cub *cub, double angle, int i);
void	renderray(t_cub *cub, double angle, int i);
void	castallrays(t_cub *cub);
double	distancebetweenpoints(int x1, int y1, int x2, int y2);
int		create_trgb(int t, int r, int g, int b);
int		haswall(int x, int y, t_cub *cub, int i);
void	key_press(t_cub *cub, int codekey);
void	update_map(t_cub *cub, int codekey);
void	renderrectangle(t_cub *cub, t_renderrctengle rect);
void	render3d(t_cub *cub);
void	update_map(t_cub *cub, int codekey);
void	my_mlx_pixel_put(t_cub *data, int x, int y, int color);
int		haswallplayer(int x, int y, t_cub *cub);
void	renderciel(t_cub *cub);
int		my_mlx_color(t_cub *data, int x, int y, int i);
int		parser(t_cub *cub, char *file);
int		verify_file(char **lines);
int		is_color(char *line);
int		is_texture(char *line);
int		parser_map(t_cub *cub, char **lines);
int		parser_texture(t_cub *cub, char **lines);
int		parser_color(t_cub *cub, char **lines);
void	t_cub_init(t_cub *cub);
char	**read_file(char *file_name);
void	free_array_string(char **array);
int		array_len(char **array);
int		longest_line(char **array);
int		empty_line(char *line);
char	*advance_whitespace(char *line);
int		check_file(char *file_name);
char	*get_next_line(int fd);
int		get_texture(t_cub *cub, char *line);
int		valid_textures(t_cub *cub);
int		get_color(t_cub *cub, char *line);
int		valid_colors(t_cub *cub);
char	*remove_spaces(char *line);
int		valid_map_lines(t_cub *cub);
int		valid_player(t_cub *cub);
int		valid_map_space(t_cub *cub, int i, int j);
int		valid_map(t_cub *cub);
int		get_map(t_cub *cub, char **line);
int		is_map(char *line);
char	**get_rgb(char *line);
int		get_index_of_map(char **lines);
int		set_textures(t_cub *cub);
void	render_map_loop(t_cub *cub, int i, int j);
int		set_textures_get_data(t_cub *cub);
void	draw_pixels(int color, int x, int y, t_cub *cub);
void	setup_map(t_cub *cub);
#endif