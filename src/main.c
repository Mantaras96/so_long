/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:22:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/03/26 15:30:26 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_global global;
		
	if (argc == 2)
	{
	global.map = validate_and_read_map(argv[1]);
	printf("Linea1:%s", global.map[0]);
	printf("Linea2:%s", global.map[1]);
	} else {
		show_error_msg("Error numero de parametro incorrecto");
		return(0);
	}
}

