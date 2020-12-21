/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:35:20 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/15 14:48:14 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_cub(t_game *g)
{
	int		fd;
	char	*str;
	char	*clean_str;

	if ((fd = open_file(g->map.filename)) == ERROR)
		return (error(CANT_OPEN));
	while (get_next_line(fd, &str))
	{
		clean_str = ft_clean_str(str);
		if (clean_str[0] != '\0')
		{
			if (is_map_line(clean_str) == ERROR)
			{
				if (g->map.size.y != 0)
					g->error = 1;
				parse_informations(g, clean_str);
			}
			if (is_map_line(str) == SUCCESS)
				g->map.size.y++;
		}
		free(str);
	}
	free(str);
	return (check_cub(g, fd));
}

int		check_cub(t_game *g, int fd)
{
	if (g->texture.floor == ERROR)
		return (error(BAD_FORMAT));
	if (g->texture.cell == ERROR)
		return (error(BAD_FORMAT));
	if (g->win.size.x <= 0 || g->win.size.y <= 0)
		return (error(BAD_FORMAT));
	if (g->map.size.y == 0)
		return (error(NO_MAP));
	if (close_file(fd) == ERROR)
		return (error(CLOSE_FILE));
	if (g->error == 1)
		return (error(BAD_FORMAT));
	return (SUCCESS);
}

void	parse_informations(t_game *g, char *str)
{
	int	id;

	id = is_identifier(str);
	if (id == RESOLUTION && g->win.size.x == 0 && g->win.size.y == 0)
		g->win.size = parse_resolution(str);
	else if (id == NORTH && g->texture.file_north == NULL)
		g->texture.file_north = ft_strdup(ft_clean_str(str + 2));
	else if (id == SOUTH && g->texture.file_south == NULL)
		g->texture.file_south = ft_strdup(ft_clean_str(str + 2));
	else if (id == WEST && g->texture.file_west == NULL)
		g->texture.file_west = ft_strdup(ft_clean_str(str + 2));
	else if (id == EAST && g->texture.file_east == NULL)
		g->texture.file_east = ft_strdup(ft_clean_str(str + 2));
	else if (id == SPRITE && g->texture.file_sprite == NULL)
		g->texture.file_sprite = ft_strdup(ft_clean_str(str + 2));
	else if (id == FLOOR && g->texture.floor == -1)
		g->texture.floor = parse_color(str);
	else if (id == CEILLING && g->texture.cell == -1)
		g->texture.cell = parse_color(str);
	else
	{
		error(BAD_FORMAT);
		free_game(g);
		exit(EXIT_FAILURE);
	}
}

t_coor	parse_resolution(char *str)
{
	char	**tmp;
	t_coor	size;
	int		i;

	tmp = ft_split(str, ' ');
	i = 0;
	while (tmp[i] != 0)
		i++;
	if (i == 3)
	{
		set_coor(&size, ft_atoi(tmp[1]), ft_atoi(tmp[2]));
		if (size.x > MAX_WIDTH)
			size.x = MAX_WIDTH;
		if (size.y > MAX_HEIGHT)
			size.y = MAX_HEIGHT;
	}
	else
	{
		set_coor(&size, -1, -1);
	}
	free_splitted(tmp);
	return (size);
}

int		parse_color(char *str)
{
	char	**color;
	int		red;
	int		green;
	int		blue;
	int		i;

	color = ft_split(++str, ',');
	i = 0;
	while (color[i] != 0)
		i++;
	if (i == 3)
	{
		red = ft_atoi(color[0]);
		green = ft_atoi(color[1]);
		blue = ft_atoi(color[2]);
	}
	free_splitted(color);
	if (i != 3 || ft_strnstr(str, ",,", ft_strlen(str)) != NULL)
		return (ERROR);
	if (red < 0 || green < 0 || blue < 0)
		return (ERROR);
	if (red > 255 || green > 255 || blue > 255)
		return (ERROR);
	return (rgb_to_int(red, green, blue));
}
