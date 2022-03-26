/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:38:08 by amantara          #+#    #+#             */
/*   Updated: 2022/03/26 15:29:40 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

typedef struct s_corde
{
	int		x;
	int		y;
}	t_corde;

typedef struct s_global
{
	void		*mlx;
	void		*win;
	void		**img;
	char		**map;
	int			width;
	int			height;
	int			collect;
	int			movements;
	t_corde		character;
}	t_global;


void show_error_msg( char *str);

char **validate_and_read_map(char *filename);

char **read_map(char *filename);
int	array_str_count(char **arr);
int ft_validate_name(char *filename);
char	**arr_push(char **arr, char *str);


#endif