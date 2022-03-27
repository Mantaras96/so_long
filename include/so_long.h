/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertmantaras <albertmantaras@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:38:08 by amantara          #+#    #+#             */
/*   Updated: 2022/03/28 00:00:14 by albertmanta      ###   ########.fr       */
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
	int			count_coll;
	int			count_exit;
	int			count_player;
    int			count_jumpline;
}	t_global;


void show_error_msg( char *str);

char **validate_and_read_map(char *filename);

char **read_map(char *filename);
int	array_str_count(char **arr);
int ft_validate_name(char *filename);
char	**arr_push(char **arr, char *str);

void validate_letters_map(t_global *global);
void read_line(char *map, t_global *global);
void validate_rectangle_walls(t_global *global);
void validate_all_leters(t_global *global);

#endif