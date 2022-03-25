/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:02:07 by amantara          #+#    #+#             */
/*   Updated: 2022/03/19 00:01:44 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

type_global	*init_global(int fd)
{
	type_global			*global;

	global = (type_global *)malloc(sizeof(type_global));
    
	init_game(global, fd);
	return (global);
}

void    *init_game(type_global *global, int fd)
{
	type_game			*map;

	global->game = (type_game *)malloc(sizeof(type_game));
    
    global->game->map = 0;
    global->game->height = 0;
    global->game->width = 0;
	init_game_map(global, fd);
}

init_game_map(type_global *global, int fd){
	char	*file;

	file = ft_calloc(1, 1);
	if (!file){
		close(fd);
		error_openingfile();
	}
	read_file(global, &file, fd);
}

read_file(type_global *global, char **file, int fd) {
		char	buf[200 + 1];
		int		read_bytes;
		char	*aux

		read_bytes = 1;
		while (read_bytes != 0){
			read_bytes = read(fd, buf, 200);
			if (read_bytes != -1){
				buf[read_bytes] = 0;
				*file = ft_strjoin(*file, buf);
				if(!*file){
					//TODO DESTRUIR TODO
				}
			} else {
				//TODO DESTRUIR TODO (file, global) y cerrar fd
			}
			
		} 
}


