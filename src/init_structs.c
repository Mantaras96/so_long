/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:02:07 by amantara          #+#    #+#             */
/*   Updated: 2022/03/15 21:06:36 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

type_global	*init_global(int fd)
{
	type_global			*global;

	global = (type_global *)malloc(sizeof(type_global));
    
	game_init(global, fd);
	return (global);
}

void    *init_game(type_global *global, int fd)
{
	type_game			*map;

	global->game = (type_game *)malloc(sizeof(type_game));
    
    global->game->map = 0;
    global->game->height = 0;
    global->game->width = 0;
    
}
