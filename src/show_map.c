/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:34:14 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/01 00:13:30 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*transform_img(void *mlx, char *image)
{
	void	*img;
	int		img_size;

	img = mlx_xpm_file_to_image(mlx, image,
			&img_size, &img_size);
	return (img);
}
 
void set_mlx_and_window(t_global *global)
{
    global->mlx = mlx_init();
	global->character.direction = 'W';
	global->window = mlx_new_window(global->mlx, ((global->width - 1) * SIZE_TEXTURE), (global->height * SIZE_TEXTURE), "so_long");
    show_map(global);
}

void    *get_map_img(t_global *global, char c, t_corde *corde){
    if (c == '1')
        return(transform_img(global->mlx, "../assets/sprites/.xmp"));
    else if (c == '0')
        return(transform_img(global->mlx, "../assets/sprites/.xmp"));
    else if (c == 'C')
    {
        global->collect++;
        return(transform_img(global->mlx, "../assets/sprites/.xmp"));
    }
    else if (c == 'E')
        return(transform_img(global->mlx, "../assets/sprites/.xmp"));
    else if (c == 'P')
    {
        global->character.y = corde->y;
        global->character.x = corde->x;
        return(transform_img(global->mlx, "../assets/sprites/.xmp"));        
    }
    return (NULL);
}

void    show_map(t_global *global){
    int     count;
    t_corde c;
    t_corde coord;

    c.x = 0;
    count = 0;
    coord.y = 0;
    global->collect = 0;
    while (global->map[c.x])
    {
        c.y = 0;
        coord.x = 0;
        while (global->map[c.x][c.y] != '\n' && global->map[c.x][c.y])
        {
            global->img[count] = get_map_img(global, global->map[c.x][c.y], &c);
            if (global->img[count] == NULL){
                show_error_msg("Error de img");
            }
            mlx_put_image_to_window(global->mlx, global->win, global->img[count++],
				coord.x, coord.y);
            coord.x += SIZE_TEXTURE;
			c.y++;
		}
		coord.y += SIZE_TEXTURE;
		c.x++;    
        }
    }
    
    
    
    global;
}