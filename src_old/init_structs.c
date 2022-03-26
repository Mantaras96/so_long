/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:02:07 by amantara          #+#    #+#             */
/*   Updated: 2022/03/26 00:22:42 by amantara         ###   ########.fr       */
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

	(void) map;
	global->game = (type_game *)malloc(sizeof(type_game));
    
    global->game->map = 0;
    global->game->height = 0;
    global->game->width = 0;
	global->game->count_coll = 0;
	global->game->count_exit = 0;
	global->game->count_player = 0;
	
	init_game_map(global, fd);

	return(0);
}

int init_game_map(type_global *global, int fd){
	char	*file;

	file = ft_calloc(1, 1);
	if (!file){
		close(fd);
		error_openingfile();
		return(0);
	}
	read_file(global, &file, fd);
	get_width(global, file);
	get_height(global, file);
	map_is_valid(global, file);
	printf("%s", file);
	return (0);
}

void read_file(type_global *global, char **file, int fd) {
		char	buf[200 + 1];
		int		read_bytes;
		char	*aux;

		(void) aux;
		(void) *global;
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


