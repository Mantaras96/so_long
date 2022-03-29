/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:34:14 by albertmanta       #+#    #+#             */
/*   Updated: 2022/03/29 20:49:45 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
 
void set_mlx_and_window(t_global *global)
{
    global->mlx = mlx_init();
	global->character.direction = 'W';
	global->window = mlx_new_window(global->mlx, ((global->width - 1) * SIZE_TEXTURE), (global->height * SIZE_TEXTURE), "so_long");
    show_map(global);
}

void    *complete_map_img(t_global *global, char c, t_corde *corde){
    if (c == '1')
        return(select_img_wall(global));
    else if (c == '0')
        return(select_img_ground(global));
    else if (c == 'C')
    {
        global->collect++;
        return(select_img_collect(global));
    }
    else if (c == 'E')
        return(select_img_escape(global));
    else if (c == 'P')
    {
        global->character.y = corde->y;
        global->character.x = corde->x;
        return(select_img_player(global));        
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
            global->img[count] = complete_map_img(global, global->map[c.x][c.y], &c);
            if (global->img[count] == NULL){
                show_error_msg("Error de img");
            }
        }
    }
    
    
    
    global;
}