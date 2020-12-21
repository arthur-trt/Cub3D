/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:03:56 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/21 10:20:28 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_mlx(t_window *w)
{
	if (!(w->mlx_ptr = mlx_init()))
		return (ERROR);
	if (!(w->ptr = mlx_new_window(w->mlx_ptr, w->size.x, w->size.y, "Cub3D")))
		return (ERROR);
	if (!(w->img.ptr = mlx_new_image(w->mlx_ptr, w->size.x, w->size.y)))
		return (ERROR);
	w->img.data = mlx_get_data_addr(w->img.ptr, &w->img.bpp, &w->img.size_line,
		&w->img.endian);
	return (SUCCESS);
}

int		init_mlx_screenshot(t_window *w)
{
	if (!(w->mlx_ptr = mlx_init()))
		return (ERROR);
	if (!(w->img.ptr = mlx_new_image(w->mlx_ptr, w->size.x, w->size.y)))
		return (ERROR);
	w->img.data = mlx_get_data_addr(w->img.ptr, &w->img.bpp, &w->img.size_line,
		&w->img.endian);
	return (SUCCESS);
}

int		init_image(t_window w, t_img *img)
{
	if (!(img->ptr = mlx_new_image(w.mlx_ptr, w.size.x, w.size.y)))
		return (0);
	img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line,
		&img->endian);
	return (1);
}

void	update_screen(t_window *w)
{
	mlx_put_image_to_window(w->mlx_ptr, w->ptr, w->img.ptr, 0, 0);
	mlx_destroy_image(w->mlx_ptr, w->img.ptr);
	init_image(*w, &w->img);
}
