/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_width_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:23:18 by albertmanta       #+#    #+#             */
/*   Updated: 2022/03/26 00:48:10 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_width(type_global *global, char *map){
    int i;

    i = 0;
    while(map[i] && map[i] != '\n'){
        i++;
    }
    printf("Width: %d", i);
    global->game->width = i;
}

void get_height(type_global *global, char *map){
    int i;
    int j;

    i = 0;
    j = 1;
    while(map[i]){
        if (map[i] == '\n')
        j++;
    i++;
    }
    i++;
    printf("Height: %d\n", j);
    global->game->height = j;
}

/*
    Funcion que valida que esta rodeado de walls hay personaje y salida.
*/
void map_is_valid(type_global *global, char *map){
    int i;

    i = 0;
    while (map[i]){
        if (map[i] == '\n')
            i++;
        if (is_border(i, global->game->width, global->game->height))
        {
            if(map[i] != '1'){
              free(map); // Matar objeto global;
              error_walls_map(); 
            }
        } else {
            valid_letter(global, map, i);
        }
        i++;   
    }
    if(global->game->count_coll < 1 || global->game->count_exit != 1 || global->game->count_player != 1 || global->game->width == global->game->height){
        free(map);
        error_walls_map();
    }
    
}

static int	is_border(int i, int width, int height)
{
	if (i < width
		|| i > (width + 1) * (height - 1)
		|| i % (width + 1) == 0
		|| i % (width + 1) == width - 1)
		return (1);
	return (0);
}

/*
Funcion que evalua los objetos del mapa
TODO: N por si quiero agregar enemigos. 
*/
static void	valid_letter(type_global *global, char *map, int i)
{
    if (map[i] == 1 )
    return;
    else if (map[i] == '0')
    return;
    else if (map[i] == 'E')
        global->game->count_exit++;
    else if (map[i] == 'C')
        global->game->count_coll++;
    else if (map[i] == 'N')
        return;
    else if (map[i] == 'P')
        global->game->count_player++;
    else {
        free(map);
        error_invalid_map();
    }
}



