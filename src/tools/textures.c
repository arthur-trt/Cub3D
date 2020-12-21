/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:21:30 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/08 11:29:37 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_texture(t_game *g)
{
	if (load_texture_from_file(g->win,
		&g->texture.north, g->texture.file_north) == ERROR)
		return (ERROR);
	if (load_texture_from_file(g->win,
		&g->texture.south, g->texture.file_south) == ERROR)
		return (ERROR);
	if (load_texture_from_file(g->win,
		&g->texture.east, g->texture.file_east) == ERROR)
		return (ERROR);
	if (load_texture_from_file(g->win,
		&g->texture.west, g->texture.file_west) == ERROR)
		return (ERROR);
	if (load_texture_from_file(g->win,
		&g->texture.sprite, g->texture.file_sprite) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	load_texture_from_file(t_window w, t_img *t, char *filename)
{
	t->ptr = mlx_xpm_file_to_image(w.mlx_ptr, filename, &t->width, &t->height);
	if (t->ptr == NULL)
		return (ERROR);
	t->data = mlx_get_data_addr(t->ptr, &t->bpp, &t->size_line, &t->endian);
	return (SUCCESS);
}
