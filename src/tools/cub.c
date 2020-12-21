/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:24:28 by atrouill          #+#    #+#             */
/*   Updated: 2020/10/19 15:32:53 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_identifier(char *str)
{
	if (ft_strncmp(str, "R ", 2) == 0)
		return (RESOLUTION);
	if (ft_strncmp(str, "NO ", 3) == 0)
		return (NORTH);
	if (ft_strncmp(str, "SO ", 3) == 0)
		return (SOUTH);
	if (ft_strncmp(str, "WE ", 3) == 0)
		return (WEST);
	if (ft_strncmp(str, "EA ", 3) == 0)
		return (EAST);
	if (ft_strncmp(str, "S ", 2) == 0)
		return (SPRITE);
	if (ft_strncmp(str, "F ", 2) == 0)
		return (FLOOR);
	if (ft_strncmp(str, "C ", 2) == 0)
		return (CEILLING);
	return (ERROR);
}
