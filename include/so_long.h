/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:38:08 by amantara          #+#    #+#             */
/*   Updated: 2022/03/18 23:43:45 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct s_game {
	int		**map;
	int		height;
	int		width;
	
	
}	type_game;

typedef struct s_global {
	type_game			*game;

	// Propiedades para integrar mas adelante con los sprites.

	//player_up
	//player_down
	//player_left
	//player_right
	//wall
	//exit
	//flor
	//object
}	type_global;

void	error_parameters();
void	error_filename();
void	error_openingfile();

char	**check_and_get_map(char **arg2);

#endif