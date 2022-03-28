/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_letters_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:05:15 by albertmanta       #+#    #+#             */
/*   Updated: 2022/03/28 00:13:34 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void validate_rectangle_walls(t_global *global){
    int i;
    int j;

    i = 0;
    if (global->height == global->width){
        show_error_msg("El mapa tiene que ser rectangular.");
    }
    while(i < global->height){
        j= 0;
        while(global->map[i][j])
        {
            if (i == 0 || i == global->height - 1)
            {
                if (global->map[i][j] != '1' && global->map[i][j] != '\n'){
                    printf("Bicho:%d Linea:%d", global->map[i][j], i);
                    show_error_msg("Error pareder ultima primera linea");
                }    
            } else if (j == 0 || j == global->width - 2) {
                if (global->map[i][j] != '1')
                    show_error_msg("Error paredes lineas del medio"); 
            }
            j++;
        }
        i++;
    }
}

void read_line(char *map, t_global *global){
    int i;
    printf("Linia:%s\n", map);
    i = 0;
    while(map[i]) {
         write(1, "Valor:", 6);
        write(1, &map[i], 1);
        write(1, "\n", 1);
        if (map[i] == 'E')
            global->count_exit++;
        else if (map[i] == 'C')
            global->count_coll++;
        else if (map[i] == 'P')
            global->count_player++;
        else if (map[i] != '1' && map[i] != '\n' && map[i] != '0' && map[i] != 'N'  )
            show_error_msg("Parametro desconocido en una linia.");
        i++;
    }
    if (global->width == -1){
        global->width = i;
    } else if (global->width != i && global->width != i + 1)
        show_error_msg("Error de longitud en una linea.");
}

void validate_all_leters(t_global *global) {
    if (global->count_coll < 1){
        show_error_msg("Error de coleccionables.");
    }
    if (global->count_exit > 1 || global->count_exit == 0) {
        show_error_msg("Error de salidas disponibles.");
    }
    if (global->count_player > 1 || global->count_player == 0) {
        show_error_msg("Error de jugadores.");
    }
}


void validate_letters_map(t_global *global){
    int i;
    
    global->count_coll = 0;
	global->count_exit = 0;
	global->count_player = 0;
    global->count_jumpline = 0;
    global->width = -1;
    i = 0;
    while(global->map[i]){
        read_line(global->map[i], global);
        i++;
    }
    global->height = i;
    validate_all_leters(global);
    validate_rectangle_walls(global);
}
