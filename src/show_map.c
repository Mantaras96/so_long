/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:34:14 by albertmanta       #+#    #+#             */
/*   Updated: 2022/03/28 22:44:59 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void set_mlx_and_window(t_global *global)
{
    global->mlx = mlx_init();
	global->character.direction = 'W';
	global->window = mlx_new_window(global->mlx, ((global->width - 1) * SIZE_TEXTURE), (global->height * SIZE_TEXTURE), "so_long");
    show_map(global);
}

void show_map(t_global *global){
    
}