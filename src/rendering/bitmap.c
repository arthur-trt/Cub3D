/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:31:05 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/26 14:29:40 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_header(t_img img, int fd)
{
	int	size_file;
	int	img_offset;

	img_offset = 54;
	size_file = img_offset + img.width * img.height * 4;
	write(fd, "BM", 2);
	write(fd, &size_file, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &img_offset, 4);
}

void	bmp_info(t_img img, int fd)
{
	int	size_header;
	int	size_img;
	int	plane;

	size_header = 40;
	size_img = img.width * img.height * 4;
	plane = 1;
	write(fd, &size_header, 4);
	write(fd, &img.width, 4);
	write(fd, &img.height, 4);
	write(fd, &plane, 2);
	write(fd, &img.bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &size_img, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

void	bmp_img(t_img img, int fd)
{
	int	x;
	int	y;

	y = img.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < img.width)
		{
			write(fd, &img.data[y * img.size_line + x * img.bpp / 8], 1);
			write(fd, &img.data[y * img.size_line + x * img.bpp / 8 + 1], 1);
			write(fd, &img.data[y * img.size_line + x * img.bpp / 8 + 2], 1);
			write(fd, "\0", 1);
			x++;
		}
		y--;
	}
}

int		bmp(t_game *g)
{
	int	fd;

	if ((fd = open("screenshot.bmp", O_CREAT | O_WRONLY,
		S_IRWXU | S_IRWXG | S_IROTH)) < 0)
		return (error(CREATE_BMP));
	g->win.img.height = (int)(g->win.size.y);
	g->win.img.width = (int)(g->win.size.x);
	bmp_header(g->win.img, fd);
	bmp_info(g->win.img, fd);
	bmp_img(g->win.img, fd);
	close(fd);
	return (SUCCESS);
}
