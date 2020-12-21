/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:44:40 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/26 14:48:28 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	puterr(char *str)
{
	ft_putstr_fd("Error.\n", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
}

int		error(int ec)
{
	(ec == WRONG_CLI) ? puterr("Usage : ./cub3d [--save] <map.cub>") : 0;
	(ec == NOT_CUB) ? puterr("Not a valid .cub file.") : 0;
	(ec == CANT_OPEN) ? puterr("Can't open file.") : 0;
	(ec == BAD_FORMAT) ? puterr("cub file is bad formated.") : 0;
	(ec == CLOSE_FILE) ? puterr("Can't close cub file.") : 0;
	(ec == BAD_MAP) ? puterr("Map not well formated.") : 0;
	(ec == BAD_PLAYER) ? puterr("There is a problem with player position.") : 0;
	(ec == LOAD_TEXT) ? puterr("A problem occured when importing textures") : 0;
	(ec == CREATE_BMP) ? puterr("Can't create bitmap.") : 0;
	(ec == NO_MAP) ? puterr("No map found in cub file.") : 0;
	return (ERROR);
}
