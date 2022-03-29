/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:22:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/03/29 19:44:44 by amantara         ###   ########.fr       */
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
	global.img = ft_calloc(sizeof(void *), ((global.width - 1) * global.height) + 1 );
	set_mlx_and_window(&global);

	} else {
		show_error_msg("Error numero de parametro incorrecto");
		return(0);
	}
	return (0);
}

