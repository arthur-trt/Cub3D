/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 01:15:24 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/01 17:33:50 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_game *g)
{
	free(g->win.mlx_ptr);
	free_texture(&g->texture);
	free_map(&g->map);
	free(g->z_buffer);
}

void	free_texture(t_texture *t)
{
	if (t->file_north != NULL)
		free(t->file_north);
	if (t->file_south != NULL)
		free(t->file_south);
	if (t->file_west != NULL)
		free(t->file_west);
	if (t->file_east != NULL)
		free(t->file_east);
	if (t->file_sprite != NULL)
		free(t->file_sprite);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map != NULL)
	{
		while (i < map->nb_lines)
		{
			free(map->map[i]);
			i++;
		}
	}
	free(map->map);
}

void	free_splitted(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_sprite(t_sprite **s)
{
	t_sprite	*tmp;
	t_sprite	*next;

	if (s)
	{
		tmp = *s;
		while (tmp)
		{
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
		*s = NULL;
	}
}
