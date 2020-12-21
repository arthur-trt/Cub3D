/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:36:23 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/24 17:35:33 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_game *g)
{
	while (g->ray.hit != 1)
	{
		if (g->ray.side_dist.x < g->ray.side_dist.y)
		{
			g->ray.side_dist.x += g->ray.delta_dist.x;
			g->ray.map_x += g->ray.step_x;
			g->ray.side = (g->ray.step_x == -1) ? 0 : 1;
		}
		else
		{
			g->ray.side_dist.y += g->ray.delta_dist.y;
			g->ray.map_y += g->ray.step_y;
			g->ray.side = (g->ray.step_y == -1) ? 2 : 3;
		}
		if (g->map.map[g->ray.map_y][g->ray.map_x] == '1')
			g->ray.hit = 1;
		else if (g->map.map[g->ray.map_y][g->ray.map_x] == '2')
			add_sprite(g);
	}
}
