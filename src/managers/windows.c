/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:22:59 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/20 12:55:01 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy_win(t_game *g)
{
	free_game(g);
	exit(EXIT_SUCCESS);
}

int	focus_out(t_game *g)
{
	g->key.backward = 0;
	g->key.forward = 0;
	g->key.left = 0;
	g->key.right = 0;
	g->key.shift = 0;
	g->player.mov_speed = 0.17;
	return (SUCCESS);
}
