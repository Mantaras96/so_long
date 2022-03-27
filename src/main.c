/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:22:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/03/28 00:01:40 by albertmanta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_global global;
	
	if (argc == 2)
	{
	global.map = validate_and_read_map(argv[1]);
	validate_letters_map(&global);
	} else {
		show_error_msg("Error numero de parametro incorrecto");
		return(0);
	}
}

