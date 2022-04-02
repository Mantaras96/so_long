/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:34:14 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/02 16:30:25 by amantara         ###   ########.fr       */
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
	global->character.direction = 'W';
    show_map(global);
}

void	*complete_map_img(t_global *vars, int i, int j)
{
	if (vars->map[i][j] == '1')
		return (transform_img(vars->mlx, "./assets/sprites/wall.xpm"));
	else if (vars->map[i][j] == '0')
		return (transform_img(vars->mlx, "./assets/sprites/water.xpm"));
	else if (vars->map[i][j] == 'C')
	{
		vars->collect++;
		return (transform_img(vars->mlx, "./assets/sprites/collectable.xpm"));
	}
	else if (vars->map[i][j] == 'E')
		return (transform_img(vars->mlx, "./assets/sprites/escape.xpm"));
	else if (vars->map[i][j] == 'P')
	{
		vars->character.x = j;
		vars->character.y = i;
		return (transform_img(vars->mlx, "./assets/sprites/char_u.xpm"));
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
			global->img[count] = complete_map_img(global, c.x, c.y);
			if (global->img[count] == NULL){
				exit (0);
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