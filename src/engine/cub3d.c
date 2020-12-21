/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:03:33 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/24 17:49:00 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		launch_game(t_game *g)
{
	init_player_dir(&g->player);
	if (load_texture(g) == ERROR)
		return (error(LOAD_TEXT));
	if (!(g->z_buffer = malloc(g->win.size.x * sizeof(double))))
		return (ERROR);
	return (SUCCESS);
}

int		main_loop(t_game *g)
{
	key_event(g);
	raycaster(g);
	return (SUCCESS);
}
