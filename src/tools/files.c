/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:00:56 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/03 11:26:03 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		open_file(char *filename)
{
	int	fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		return (ERROR);
	}
	return (fd);
}

int		close_file(int fd)
{
	if (close(fd) == -1)
	{
		return (ERROR);
	}
	return (SUCCESS);
}
