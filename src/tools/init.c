/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:36:15 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/15 14:46:36 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *g)
{
	init_win(&g->win);
	init_texture(&g->texture);
	init_map(&g->map);
	init_player(&g->player);
	init_ray(&g->ray);
	init_keyboard(&g->key);
	g->sprites = NULL;
	g->z_buffer = NULL;
	g->save = 0;
	g->error = 0;
}

void	init_win(t_window *w)
{
	w->mlx_ptr = NULL;
	w->ptr = NULL;
	w->size.x = 0;
	w->size.y = 0;
	init_img(&w->img);
}

void	init_img(t_img *i)
{
	i->ptr = NULL;
	i->data = NULL;
	i->bpp = 0;
	i->size_line = 0;
	i->endian = 0;
	i->height = 0;
	i->width = 0;
}

void	init_texture(t_texture *t)
{
	t->file_north = NULL;
	t->file_south = NULL;
	t->file_west = NULL;
	t->file_east = NULL;
	t->file_sprite = NULL;
	init_img(&t->north);
	init_img(&t->south);
	init_img(&t->west);
	init_img(&t->east);
	init_img(&t->sprite);
	t->floor = -1;
	t->cell = -1;
}

void	init_map(t_map *m)
{
	m->filename = NULL;
	m->size.x = 0;
	m->size.y = 0;
	m->nb_lines = 0;
	m->map = NULL;
}
