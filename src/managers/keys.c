/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 23:27:19 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/16 09:28:52 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_event(t_game *g)
{
	if (g->key.forward == 1)
		move_up(&g->player, g->map);
	if (g->key.backward == 1)
		move_down(&g->player, g->map);
	if (g->key.left == 1)
		move_left(&g->player, g->map);
	if (g->key.right == 1)
		move_right(&g->player, g->map);
	if (g->key.r_left == 1)
		rotate_left(&g->player);
	if (g->key.r_right == 1)
		rotate_right(&g->player);
	if (g->key.shift == 1)
		g->player.mov_speed = 0.45;
	if (g->key.shift == 0)
		g->player.mov_speed = 0.17;
	return (SUCCESS);
}

int		key_pressed(int keycode, t_game *g)
{
	if (keycode == KEY_W && g->key.forward == 0)
		g->key.forward = 1;
	if (keycode == KEY_S && g->key.backward == 0)
		g->key.backward = 1;
	if (keycode == KEY_A && g->key.left == 0)
		g->key.left = 1;
	if (keycode == KEY_D && g->key.right == 0)
		g->key.right = 1;
	if (keycode == KEY_LEFT && g->key.r_left == 0)
		g->key.r_left = 1;
	if (keycode == KEY_RIGHT && g->key.r_right == 0)
		g->key.r_right = 1;
	if (keycode == KEY_SHIFT && g->key.shift == 0)
		g->key.shift = 1;
	if (keycode == KEY_ESC)
	{
		free_game(g);
		exit(EXIT_SUCCESS);
	}
	return (SUCCESS);
}

int		key_released(int keycode, t_game *g)
{
	if (keycode == KEY_W && g->key.forward == 1)
		g->key.forward = 0;
	if (keycode == KEY_S && g->key.backward == 1)
		g->key.backward = 0;
	if (keycode == KEY_A && g->key.left == 1)
		g->key.left = 0;
	if (keycode == KEY_D && g->key.right == 1)
		g->key.right = 0;
	if (keycode == KEY_LEFT && g->key.r_left == 1)
		g->key.r_left = 0;
	if (keycode == KEY_RIGHT && g->key.r_right == 1)
		g->key.r_right = 0;
	if (keycode == KEY_SHIFT && g->key.shift == 1)
		g->key.shift = 0;
	return (SUCCESS);
}
