/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_f_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:51:08 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/26 15:15:08 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_floor_cell(t_window *w, t_ray ray, t_texture t)
{
	int	y;

	y = 0;
	while (y < ray.draw_start)
		put_color_to_px(w, ray.x, y++, t.cell);
	y = ray.draw_end + 1;
	y = (y < 0) ? 1 : y;
	while (y < w->size.y)
		put_color_to_px(w, ray.x, y++, t.floor);
}
