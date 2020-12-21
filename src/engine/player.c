/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:24:08 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/16 09:31:30 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_player *p, t_map map)
{
	t_coor new_pos;

	set_coor(&new_pos, p->pos.x + p->dir.x * p->mov_speed,
		p->pos.y + p->dir.y * p->mov_speed);
	if (map.map[(int)p->pos.y][(int)(new_pos.x + 0.001)] == '0')
		p->pos.x = new_pos.x;
	if (map.map[(int)(new_pos.y + 0.001)][(int)p->pos.x] == '0')
		p->pos.y = new_pos.y;
}

void	move_down(t_player *p, t_map map)
{
	t_coor new_pos;

	set_coor(&new_pos, p->pos.x - p->dir.x * p->mov_speed,
		p->pos.y - p->dir.y * p->mov_speed);
	if (map.map[(int)p->pos.y][(int)(new_pos.x - 0.001)] == '0')
		p->pos.x = new_pos.x;
	if (map.map[(int)(new_pos.y - 0.001)][(int)p->pos.x] == '0')
		p->pos.y = new_pos.y;
}

void	move_right(t_player *p, t_map map)
{
	t_coor new_pos;

	set_coor(&new_pos, p->pos.x + p->plane.x * p->mov_speed,
		p->pos.y + p->plane.y * p->mov_speed);
	if (map.map[(int)p->pos.y][(int)(new_pos.x + 0.001)] == '0')
		p->pos.x = new_pos.x;
	if (map.map[(int)(new_pos.y + 0.001)][(int)p->pos.x] == '0')
		p->pos.y = new_pos.y;
}

void	move_left(t_player *p, t_map map)
{
	t_coor new_pos;

	set_coor(&new_pos, p->pos.x - p->plane.x * p->mov_speed,
		p->pos.y - p->plane.y * p->mov_speed);
	if (map.map[(int)p->pos.y][(int)(new_pos.x - 0.001)] == '0')
		p->pos.x = new_pos.x;
	if (map.map[(int)(new_pos.y - 0.001)][(int)p->pos.x] == '0')
		p->pos.y = new_pos.y;
}
