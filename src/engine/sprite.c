/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:21:22 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/26 15:14:00 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_sprite(t_game *g)
{
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
		exit(ERROR);
	init_sprite(new);
	new->map_x = g->ray.map_x;
	new->map_y = g->ray.map_y;
	new->dist = (g->player.pos.x - new->map_x) * (g->player.pos.x - new->map_x)
		+ (g->player.pos.y - new->map_y) * (g->player.pos.y - new->map_y);
	if (check_no_duplicate(g->sprites, new) == SUCCESS)
		sort_insert(&(g->sprites), new);
	else
		free(new);
}

void	sort_insert(t_sprite **sprite, t_sprite *new)
{
	t_sprite	*tmp;

	if ((*sprite) == NULL || (*sprite)->dist <= new->dist)
	{
		new->next = (*sprite);
		(*sprite) = new;
	}
	else
	{
		tmp = (*sprite);
		while (tmp->next != NULL && tmp->next->dist >= new->dist)
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}
