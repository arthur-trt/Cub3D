/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:42:16 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/16 09:21:51 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *p)
{
	set_coor(&p->pos, 0, 0);
	set_coor(&p->dir, 0, 0);
	set_coor(&p->plane, 0, 0);
	p->mov_speed = 0.17;
	p->rot_speed = 0.12;
	p->start_dir = 0;
}

void	init_keyboard(t_key *k)
{
	k->forward = 0;
	k->backward = 0;
	k->left = 0;
	k->right = 0;
	k->esc = 0;
	k->shift = 0;
	k->r_left = 0;
	k->r_right = 0;
}

void	init_player_dir(t_player *p)
{
	if (p->start_dir == 'N')
	{
		set_coor(&p->dir, 0, -1);
		set_coor(&p->plane, 0.66, 0);
	}
	else if (p->start_dir == 'S')
	{
		set_coor(&p->dir, 0, 1);
		set_coor(&p->plane, -0.66, 0);
	}
	else if (p->start_dir == 'E')
	{
		set_coor(&p->dir, 1, 0);
		set_coor(&p->plane, 0, 0.66);
	}
	else if (p->start_dir == 'W')
	{
		set_coor(&p->dir, -1, 0);
		set_coor(&p->plane, 0, -0.66);
	}
}

void	init_ray(t_ray *r)
{
	set_coor(&r->dir, 0, 0);
	r->camera = 0;
	set_coor(&r->side_dist, 0, 0);
	set_coor(&r->delta_dist, 0, 0);
	r->wall_x = 0;
	r->tex_x = 0;
	r->perp_wall_dist = 0;
	r->step_x = 0;
	r->step_y = 0;
	r->map_x = 0;
	r->map_y = 0;
	r->side = 0;
	r->hit = 0;
	r->x = 0;
	r->line_h = 0;
	r->y = 0;
}

void	init_sprite(t_sprite *s)
{
	s->dist = 0;
	s->draw_start_x = 0;
	s->draw_end_x = 0;
	s->draw_start_y = 0;
	s->draw_end_y = 0;
	set_coor(&s->pos, 0, 0);
	s->inv_det = 0;
	set_coor(&s->transform, 0, 0);
	s->screen_x = 0;
	s->height = 0;
	s->width = 0;
	s->text_x = 0;
	s->text_y = 0;
	s->map_x = 0;
	s->map_y = 0;
	s->x = 0;
	s->y = 0;
	s->next = NULL;
}
