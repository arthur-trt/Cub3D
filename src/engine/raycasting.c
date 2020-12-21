/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:49:52 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/29 14:22:59 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_delta_dist(t_ray *ray)
{
	if (ray->dir.y == 0)
		ray->delta_dist.x = 0;
	else
		ray->delta_dist.x = (ray->dir.x == 0) ? 1 : fabs(1 / ray->dir.x);
	if (ray->dir.x == 0)
		ray->delta_dist.y = 0;
	else
		ray->delta_dist.y = (ray->dir.y == 0) ? 1 : fabs(1 / ray->dir.y);
}

void	calc_side_dist(t_ray *ray, t_player player)
{
	if (ray->dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (player.pos.x - ray->map_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - player.pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (player.pos.y - ray->map_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - player.pos.y)
			* ray->delta_dist.y;
	}
}

void	get_perp(t_ray *r, t_player p, t_window w)
{
	if (r->side == 0 || r->side == 1)
		r->perp_wall_dist = fabs((r->map_x - p.pos.x + (1 - r->step_x) / 2)
			/ r->dir.x);
	else if (r->side == 2 || r->side == 3)
		r->perp_wall_dist = fabs((r->map_y - p.pos.y + (1 - r->step_y) / 2)
			/ r->dir.y);
	r->line_h = (int)(fabs((w.size.y / r->perp_wall_dist)));
}

void	calc_ray(t_ray *ray, t_player *player, t_window win)
{
	ray->hit = 0;
	ray->y = 0;
	ray->line_h = 0;
	ray->camera = 2 * ray->x / win.size.x - 1;
	ray->dir.x = player->dir.x + player->plane.x * ray->camera;
	ray->dir.y = player->dir.y + player->plane.y * ray->camera;
	calc_delta_dist(ray);
	ray->map_x = (int)player->pos.x;
	ray->map_y = (int)player->pos.y;
	calc_side_dist(ray, *player);
}

void	raycaster(t_game *game)
{
	ft_bzero(game->z_buffer, game->win.size.x * sizeof(double));
	game->ray.x = 0;
	while (game->ray.x < game->win.size.x)
	{
		calc_ray(&game->ray, &game->player, game->win);
		dda(game);
		get_perp(&game->ray, game->player, game->win);
		game->z_buffer[game->ray.x] = game->ray.perp_wall_dist;
		render_text(&game->ray, &game->texture, &game->win, game->player);
		render_floor_cell(&game->win, game->ray, game->texture);
		game->ray.x++;
	}
	if (game->sprites != NULL)
		render_sprite(game);
	if (game->save == 1)
	{
		bmp(game);
		destroy_win(game);
	}
	update_screen(&game->win);
}
