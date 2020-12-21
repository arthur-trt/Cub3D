/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:37:57 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/03 11:30:03 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parse_args(t_game *game, int argc, char *argv[])
{
	char	*filename;

	if (argc == 1 || argc >= 4)
		return (error(WRONG_CLI));
	if (argc == 3)
	{
		if (ft_strncmp(argv[1], "--save", 7) != 0)
			return (error(WRONG_CLI));
		game->save = 1;
	}
	filename = ft_clean_str((argc == 2) ? argv[1] : argv[2]);
	if (is_cub_file(filename) == ERROR)
		return (error(NOT_CUB));
	game->map.filename = filename;
	return (SUCCESS);
}
