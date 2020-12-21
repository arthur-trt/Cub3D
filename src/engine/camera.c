/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 09:31:36 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/16 09:31:46 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	p->dir.x = p->dir.x * cos(-p->rot_speed) - p->dir.y * sin(-p->rot_speed);
	p->dir.y = old_dir_x * sin(-p->rot_speed) + p->dir.y * cos(-p->rot_speed);
	p->plane.x = p->plane.x * cos(-p->rot_speed)
		- p->plane.y * sin(-p->rot_speed);
	p->plane.y = old_plane_x * sin(-p->rot_speed)
		+ p->plane.y * cos(-p->rot_speed);
}

void	rotate_right(t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	p->dir.x = p->dir.x * cos(p->rot_speed) - p->dir.y * sin(p->rot_speed);
	p->dir.y = old_dir_x * sin(p->rot_speed) + p->dir.y * cos(p->rot_speed);
	p->plane.x = p->plane.x * cos(p->rot_speed)
		- p->plane.y * sin(p->rot_speed);
	p->plane.y = old_plane_x * sin(p->rot_speed)
		+ p->plane.y * cos(p->rot_speed);
}
