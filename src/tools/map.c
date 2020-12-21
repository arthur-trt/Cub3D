/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:11:08 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/26 14:27:31 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map_line(char *str)
{
	if (*str == '\0')
		return (ERROR);
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '0' && *str != '1' && *str != '2' &&
			*str != 'N' && *str != 'S' && *str != 'W' && *str != 'E')
			return (ERROR);
		str++;
	}
	return (SUCCESS);
}

double	obtain_map_size(t_map map)
{
	int		i;
	double	x;

	i = 0;
	x = 0;
	while (i < map.size.y)
	{
		if (ft_strlen(map.map[i]) > x)
			x = ft_strlen(map.map[i]);
		i++;
	}
	return (x);
}

void	arrange_map_line(t_map *map)
{
	int	i;
	int	old_size;

	i = 0;
	while (i < map->size.y)
	{
		old_size = ft_strlen(map->map[i]);
		if (old_size < map->size.x)
		{
			map->map[i] = ft_realloc(map->map[i], map->size.x);
			while (old_size < map->size.x)
			{
				map->map[i][old_size] = '1';
				old_size++;
			}
		}
		i++;
	}
}

int		verify_map(t_map map)
{
	int i;

	i = 0;
	while (i < map.size.x)
	{
		if (map.map[0][i] != '1' || map.map[(int)(map.size.y) - 1][i] != '1')
			return (ERROR);
		i++;
	}
	i = 0;
	while (i < map.size.y)
	{
		if (map.map[i][0] != '1' || map.map[i][(int)(map.size.x) - 1] != '1')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int		verify_player(t_map *map, t_player *p)
{
	int i;
	int j;

	i = 0;
	while (i < map->size.y)
	{
		j = 0;
		while (j < map->size.x)
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' ||
				map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				if (p->start_dir != 0)
					return (ERROR);
				set_coor(&p->pos, j + 0.5, i + 0.5);
				p->start_dir = map->map[i][j];
				map->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
