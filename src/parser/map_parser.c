/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:17:46 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/26 15:10:48 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_parser(t_map *map, t_player *p)
{
	int		fd;
	char	*str;

	map->map = (char **)malloc(map->size.y * sizeof(char *));
	if ((fd = open_file(map->filename)) == ERROR)
		return (error(CANT_OPEN));
	while (get_next_line(fd, &str))
	{
		if (is_map_line(str) == SUCCESS)
		{
			map->map[map->nb_lines] = (char *)malloc(ft_strlen(str)
				* sizeof(char) + 1);
			line_to_array(map->map[map->nb_lines], str);
			map->nb_lines++;
		}
		else if (map->nb_lines != 0)
			break ;
		free(str);
	}
	free(str);
	return (check_map(map, p, fd));
}

int		check_map(t_map *map, t_player *p, int fd)
{
	if (close_file(fd) == ERROR)
		return (error(CLOSE_FILE));
	if (map->size.y != map->nb_lines)
		return (error(BAD_MAP));
	map->size.x = obtain_map_size(*map);
	arrange_map_line(map);
	if (verify_map(*map) != SUCCESS)
		return (error(BAD_MAP));
	if (verify_player(map, p) != SUCCESS)
		return (error(BAD_PLAYER));
	return (SUCCESS);
}

void	line_to_array(char *map_line, char *file_line)
{
	int	i;

	i = 0;
	while (file_line[i] != '\0')
	{
		if (file_line[i] == ' ')
		{
			map_line[i] = '1';
		}
		else
		{
			map_line[i] = file_line[i];
		}
		i++;
	}
	map_line[i] = '\0';
}
