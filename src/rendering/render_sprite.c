/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:56:36 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/21 10:37:09 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_sprite(t_game *g)
{
	t_sprite	*tmp;

	tmp = g->sprites;
	while (tmp != NULL)
	{
		sprite_transformation(tmp, g->player, g->win);
		sprite_sizing(tmp, g->win);
		copy_sprite_img(&g->win, tmp, g->texture, g->z_buffer);
		tmp = tmp->next;
	}
	free_sprite(&g->sprites);
}

void	copy_sprite_img(t_window *w, t_sprite *s, t_texture t, double *z_buffer)
{
	s->x = s->draw_start_x;
	while (s->x < s->draw_end_x)
	{
		if (s->transform.y > 0 && s->transform.y < z_buffer[s->x])
		{
			s->y = s->draw_start_y;
			s->text_x = (int)(t.sprite.size_line *
				(s->x - (-s->width / 2 + s->screen_x)) *
				t.sprite.width / s->width) / t.sprite.size_line;
			while (s->y < s->draw_end_y)
			{
				copy_sprite_img_helper(w, s, t);
				s->y++;
			}
		}
		s->x++;
	}
}

void	copy_sprite_img_helper(t_window *w, t_sprite *s, t_texture t)
{
	int	d;
	int	color;
	int	is;
	int	i;

	d = s->y * t.sprite.size_line
		- w->size.y * t.sprite.size_line / 2
		+ s->height * t.sprite.size_line / 2;
	s->text_y = (int)(d * t.sprite.height / s->height / t.sprite.size_line);
	is = s->text_y * t.sprite.size_line + s->text_x * t.sprite.bpp / 8;
	if (is >= 0)
	{
		color = t.sprite.data[is] + t.sprite.data[is + 1] +
			t.sprite.data[is + 2];
		i = s->y * w->img.size_line + s->x * w->img.bpp / 8;
		if (color != 0 && i >= 0)
		{
			w->img.data[i] = t.sprite.data[is];
			w->img.data[i + 1] = t.sprite.data[is + 1];
			w->img.data[i + 2] = t.sprite.data[is + 2];
		}
	}
}
