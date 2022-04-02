/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:22:17 by albertmanta       #+#    #+#             */
/*   Updated: 2022/04/02 17:17:44 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int close_event(int keycode, t_global *global){
	ft_putnbr_fd(keycode, 1);
	ft_putchar_fd(':', 1);
	ft_putnbr_fd(global->character.x, 1);
	exit(0);	
}

void	*select_img(t_global *vars, char *image)
{
	void	*img;
	int		img_size;

	img = mlx_xpm_file_to_image(vars->mlx, image,
			&img_size, &img_size);		
	return (img);
}

int	main(int argc, char **argv)
{
	t_global global;
	
	if (argc == 2)
	{
	global.map = validate_and_read_map(argv[1]);
	validate_letters_map(&global);
	global.img = ft_calloc(sizeof(void *), ((global.width - 1) * (global.height)) + 1);
	if (global.img == NULL)
		return (0);
	global.mlx = mlx_init();
	global.win = mlx_new_window(global.mlx, ((global.width - 1) * SIZE_TEXTURE), (global.height * SIZE_TEXTURE), "so_long");
	global.character.direction = 'D';
	set_mlx_and_window(&global);
	mlx_hook(global.win, 2, 0, mover, &global);
	mlx_loop(global.mlx);
	} else {
		show_error_msg("Error numero de parametro incorrecto");
		return(0);
	}
	return (0);
}

