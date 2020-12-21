/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:33:19 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/30 15:04:45 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_text(t_ray *r, t_texture *t, t_window *win, t_player p)
{
	int color;

	color = 0;
	r->draw_start = (-r->line_h + win->size.y) / 2;
	r->draw_start = (r->draw_start < 0) ? 0 : r->draw_start;
	r->draw_end = (r->line_h + win->size.y - 1) / 2;
	r->draw_end = (r->draw_end >= win->size.y) ? win->size.y - 1 : r->draw_end;
	if (r->side == 0 || r->side == 1)
		r->wall_x = p.pos.y + r->perp_wall_dist * r->dir.y;
	else
		r->wall_x = p.pos.x + r->perp_wall_dist * r->dir.x;
	r->wall_x -= floor(r->wall_x);
	r->wall_x = (r->wall_x == 0.0) ? 0.001 : r->wall_x;
	calc_wall(r, t, win);
}

void	calc_wall(t_ray *r, t_texture *t, t_window *w)
{
	t_img	tmp_text;

	tmp_text = t->south;
	tmp_text = (r->side == 0) ? t->west : tmp_text;
	tmp_text = (r->side == 1) ? t->east : tmp_text;
	tmp_text = (r->side == 2) ? t->north : tmp_text;
	r->tex_x = (int)(r->wall_x * tmp_text.width);
	if ((r->side == 0 || r->side == 1) && r->dir.x > 0)
		r->tex_x = tmp_text.width - r->tex_x - 1;
	if ((r->side == 2 || r->side == 3) && r->dir.y < 0)
		r->tex_x = tmp_text.width - r->tex_x - 1;
	copy_text_img(w, r, tmp_text);
}

void	copy_text_img(t_window *w, t_ray *r, t_img t)
{
	int	d;

	r->y = r->draw_start;
	while (r->y <= r->draw_end && r->line_h > 0)
	{
		d = r->y * t.size_line - w->size.y
				* t.size_line / 2 + r->line_h * t.size_line / 2;
		r->tex_y = ((d * t.height) / r->line_h) / t.size_line;
		if (r->tex_y >= 0)
		{
			w->img.data[r->y * w->img.size_line + r->x * w->img.bpp / 8] =
				t.data[r->tex_y * t.size_line + r->tex_x * (t.bpp / 8)];
			w->img.data[r->y * w->img.size_line + r->x * w->img.bpp / 8 + 1] =
				t.data[r->tex_y * t.size_line + r->tex_x * (t.bpp / 8) + 1];
			w->img.data[r->y * w->img.size_line + r->x * w->img.bpp / 8 + 2] =
				t.data[r->tex_y * t.size_line + r->tex_x * (t.bpp / 8) + 2];
		}
		r->y++;
	}
}
