/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:38:08 by amantara          #+#    #+#             */
/*   Updated: 2022/03/25 16:51:36 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_game {
	int		**map;
	int		height;
	int		width;
		
}	type_game;

typedef struct s_global {
	type_game			*game;
}	type_global;

void	error_parameters();
void	error_filename();
void	error_openingfile();

int check_and_get_map(char *filename);
type_global	*init_global(int fd);
void    *init_game(type_global *global, int fd);
int init_game_map(type_global *global, int fd);
void read_file(type_global *global, char **file, int fd);

#endif