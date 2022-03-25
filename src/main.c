/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:22:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/03/25 16:52:33 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_and_get_map(char *filename){

	int fd;
	
	if (!ft_strnstr(filename, ".ber", ft_strlen(filename))){
		error_filename();
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0){
		error_openingfile();
		return (0);
	}
	return (fd);
}


int	main(int arg1, char **arg2)
{
	type_global *global = NULL;
	int fd;

	if (arg1 == 2)
	{
		fd = check_and_get_map(arg2[1]);
		global = init_global(fd);
		(void) global;
	} else {
		error_parameters();
		return(0);
	}
}

