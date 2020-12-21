/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:22:37 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/30 15:11:31 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d(t_game game)
{
	if (game.save == 1)
	{
		if (init_mlx_screenshot(&game.win) == ERROR
			|| launch_game(&game) == ERROR)
			destroy_win(&game);
		raycaster(&game);
	}
	else
	{
		if (init_mlx(&(game.win)) == ERROR || launch_game(&game) == ERROR)
			destroy_win(&game);
		mlx_hook(game.win.ptr, X_KEY_PRESS, X_M_KEY_PRESS, key_pressed, &game);
		mlx_hook(game.win.ptr, X_KEY_RELEASE, X_M_KEY_RELEASE, key_released,
			&game);
		mlx_hook(game.win.ptr, X_EXIT_WIN, X_M_STRUCTNOTIF, destroy_win,
			&game);
		mlx_hook(game.win.ptr, 33, 0, destroy_win, &game);
		mlx_hook(game.win.ptr, X_FOCUSOUT, X_M_FOCUS, focus_out, &game);
		mlx_loop_hook(game.win.mlx_ptr, main_loop, &game);
		mlx_loop(game.win.mlx_ptr);
	}
}

int		main(int argc, char *argv[])
{
	t_game	game;

	init_game(&game);
	if (ft_parse_args(&game, argc, argv) == ERROR
		|| parse_cub(&game) == ERROR
		|| map_parser(&game.map, &game.player) == ERROR)
	{
		free_game(&game);
		return (EXIT_FAILURE);
	}
	cub3d(game);
	free_game(&game);
	return (EXIT_SUCCESS);
}
