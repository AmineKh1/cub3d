/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloufra <heloufra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:16:33 by akhouya           #+#    #+#             */
/*   Updated: 2023/02/24 17:18:25 by heloufra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_cub *data, int x, int y, int color)
{
    if (y > 0 && y < data->window_height && x > 0 && x < data->window_width)
	data->data[y * data->window_width + x] = color;
}

void setup_map(t_cub *cub) {
    cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx,
			 cub->window_width, cub->window_height, "cub");
    cub->player.radius = 4;
    cub->player.turnDirection = 0;
    cub->player.movespeed = 3;
    cub->player.rotationangle = 90;
    cub->player.rotationSpeed = 3 * (M_PI / 180);
    cub->player.walkDirection = 0;
    int i = -1;
    int j = 0;
    int endian = 0;
    int px = CUBPX;
    int linesize = 0;
    cub->img_ptr = mlx_new_image(cub->mlx, cub->window_width, cub->window_height);
    cub->data = (int *)mlx_get_data_addr(cub->img_ptr, &px, &linesize, &endian);
    while(++i < 14)
    {
        j = -1;
      
        while(cub->map[i][++j] != '\0')
        {
            if(cub->map[i][j] != '\0' && cub->map[i][j] == 'W')
            {
                cub->player.x = j * CUBPX;
                cub->player.y = i * CUBPX;
            }
        }
    }
}
void draw_pixels(int color, int x, int y, t_cub *cub) {
    int i = -1;
    int j = -1;
    while(++i < CUBPX)
    {
        j = -1;
        while (++j < CUBPX)
            my_mlx_pixel_put(cub,  cub->minimap * (x + i), cub->minimap * (y + j), color);
    }
}

void draw_circle(int color, t_cub *cub) {
    int i = 0;
    int j = 0;
    double x1;
    double y1;
    double angle;
    
    while (j < cub->player.radius) {
        
    i = 0;
    while (i < 360) {
        angle = i;
        x1 = j * cos(angle * M_PI / 180);
        y1 = j * sin(angle * M_PI / 180);
        my_mlx_pixel_put(cub,  (cub->minimap * (cub->player.x + x1)),(cub->minimap * (cub->player.y + y1)), color);
        i++;
    }
    j++;
    }
}

void rander_map(t_cub *cub) {
    int i = -1;
    int j = 0;
    int endian = 0;
    int px = CUBPX;
    int linesize = 0;
    // mlx_clear_window(cub->mlx, cub->win);
    
    mlx_destroy_image(cub->mlx, cub->img_ptr);
    cub->img_ptr = mlx_new_image(cub->mlx, cub->window_width, cub->window_height);
    cub->data = (int *)mlx_get_data_addr(cub->img_ptr, &px, &linesize, &endian);
    // mlx_destroy_window(cub->mlx, cub->win);
    while(++i < 14)
    {
        j = -1;
        while(cub->map[i][++j] != '\0')
        {
            if(cub->map[i][j] != '\0' && cub->map[i][j] == '1')
                draw_pixels(create_trgb(1, 255, 255, 255), j * cub->cubpx, i * cub->cubpx, cub);
            if(cub->map[i][j] != '\0' && cub->map[i][j] == 'W')
            {
                draw_circle(create_trgb(1, 136, 8, 8), cub);
                // line(cub);
                castAllRays(cub);
            }

                
        }
    }
    renderciel(cub);
    render3d(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img_ptr, 0, 0);
}



int draw_map(int key ,t_cub *cub) {


    update_map(cub, key);
    rander_map(cub);

    
    
    return 0;
}
int main(int argc, char *argv[]) {
    t_cub *cub= ft_calloc(1, sizeof(t_cub));
	// cub.lent.y = 10;

    if (argc != 2)
        return (1);
    (void)argv[1];
    // cub->map = (char**)malloc(15 * sizeof(char*));
    // cub->map[0] = strdup("111111111111111111111111111111111");
    // cub->map[1] = strdup("111111  1000000000000000000000001");
    // cub->map[2] = strdup("1000011111010000000000000011100011");
    // cub->map[3] = strdup("11000000000100111100100001111111111");
    // cub->map[4] = strdup("100011111111001 1000110000000000111");
    // cub->map[5] = strdup("11111111100000111000000000000111111");
    // cub->map[6] = strdup("1100000000001000000W000001111111");
    // cub->map[7] = strdup(" 11111111111111100000000000000011");
    // cub->map[8] = strdup("1100001        10001000000011111111");
    // cub->map[9] = strdup("11000011111 1111000111100000111111111");
    // cub->map[10] = strdup("10000000001110000001 100000111");
    // cub->map[11] = strdup("11000001111100011111111111011");
    // cub->map[12] = strdup("11111111 1110111 10111010100011");
    // cub->map[13] = strdup("11111111 1111111 1111111111111");
    // cub->map[14] = NULL;
    if (!parser(cub, argv[1]))
    {
        system("leaks cub3d");
        return (1); 
    }
    int i;
    

    printf("SO = %s\n", cub->SO);
    printf("NO = %s\n", cub->NO);
    printf("WE = %s\n", cub->WE);
    printf("EA = %s\n", cub->EA);
    printf("F = %x\n", cub->F);
    printf("C = %x\n", cub->C);
    printf("map\n");
    i = 0;
    while (i < 14)
    {
        printf("%s\n", cub->map[i]);
        i++;
    }
    system("leaks cub3d");
    cub->rayc = malloc(cub->num_rays * sizeof(t_rayc));

    cub->data = malloc(sizeof(char*) * 14);
    setup_map(cub);
    rander_map(cub);
    mlx_hook(cub->win, 2, 0, &draw_map, cub);
	mlx_loop(cub->mlx);
    
}