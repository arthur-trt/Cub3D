/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:03:15 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/25 14:04:02 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_no_duplicate(t_sprite *sprite, t_sprite *new)
{
	t_sprite	*tmp;

	if (sprite)
	{
		tmp = sprite;
		while (tmp)
		{
			if (tmp->map_x == new->map_x && tmp->map_y == new->map_y)
				return (ERROR);
			tmp = tmp->next;
		}
	}
	return (SUCCESS);
}

void	sprite_transformation(t_sprite *s, t_player p, t_window w)
{
	s->pos.x = s->map_x - (p.pos.x - 0.5);
	s->pos.y = s->map_y - (p.pos.y - 0.5);
	s->inv_det = 1.0 / (p.plane.x * p.dir.y - p.dir.x * p.plane.y);
	s->transform.x = s->inv_det * (p.dir.y * s->pos.x - p.dir.x * s->pos.y);
	s->transform.y = s->inv_det * (p.plane.x * s->pos.y - p.plane.y * s->pos.x);
	s->screen_x = (int)((w.size.x / 2) * (1 + s->transform.x / s->transform.y));
}

void	sprite_sizing(t_sprite *s, t_window w)
{
	s->height = abs((int)(w.size.y / s->transform.y));
	s->draw_start_y = -s->height / 2 + w.size.y / 2;
	s->draw_start_y = (s->draw_start_y < 0) ? 0 : s->draw_start_y;
	s->draw_end_y = s->height / 2 + w.size.y / 2;
	s->draw_end_y = (s->draw_end_y >= w.size.y) ? w.size.y - 1 : s->draw_end_y;
	s->width = abs((int)(w.size.y / s->transform.y));
	s->draw_start_x = -s->width / 2 + s->screen_x;
	s->draw_start_x = (s->draw_start_x < 0) ? 0 : s->draw_start_x;
	s->draw_end_x = s->width / 2 + s->screen_x;
	s->draw_end_x = (s->draw_end_x >= w.size.x) ? w.size.x - 1 : s->draw_end_x;
}
