/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:23:18 by albertmanta       #+#    #+#             */
/*   Updated: 2022/03/25 16:52:27 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_parameters(){
    ft_putstr_fd("Numero de parametros incorrecto", 1);
}

void error_filename(){
    ft_putstr_fd("El fichero tiene que ser de tipo .ber.", 1);
}

void error_openingfile(){
    ft_putstr_fd("Error abriendo el archivo indicado.", 1);
}
