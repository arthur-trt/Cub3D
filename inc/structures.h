/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:21:23 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/16 09:21:27 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_coor
{
	double			x;
	double			y;
}					t_coor;

typedef struct		s_key
{
	int				forward;
	int				backward;
	int				left;
	int				right;
	int				esc;
	int				shift;
	int				r_left;
	int				r_right;
}					t_key;

typedef struct		s_map
{
	char			*filename;
	t_coor			size;
	int				nb_lines;
	char			**map;
}					t_map;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_texture
{
	char			*file_north;
	char			*file_south;
	char			*file_west;
	char			*file_east;
	char			*file_sprite;
	t_img			north;
	t_img			south;
	t_img			west;
	t_img			east;
	t_img			sprite;
	int				floor;
	int				cell;
	int				text_x;
	int				text_y;
}					t_texture;

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*ptr;
	t_coor			size;
	t_img			img;
}					t_window;

typedef struct		s_player
{
	t_coor			pos;
	t_coor			dir;
	t_coor			plane;
	char			start_dir;
	double			mov_speed;
	double			rot_speed;
}					t_player;

typedef struct		s_ray
{
	t_coor			dir;
	t_coor			side_dist;
	t_coor			delta_dist;
	double			camera;
	double			perp_wall_dist;
	double			*buffer;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	int				draw_start;
	int				draw_end;
	int				line_h;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				side;
	int				hit;
	int				x;
	int				y;
}					t_ray;

typedef struct		s_sprite
{
	double			dist;
	int				draw_start_x;
	int				draw_end_x;
	int				draw_start_y;
	int				draw_end_y;
	t_coor			pos;
	double			inv_det;
	t_coor			transform;
	int				screen_x;
	int				height;
	int				width;
	int				text_x;
	int				text_y;
	int				map_x;
	int				map_y;
	int				x;
	int				y;
	struct s_sprite	*next;
}					t_sprite;

typedef struct		s_game
{
	t_window		win;
	t_texture		texture;
	t_map			map;
	t_player		player;
	t_ray			ray;
	t_key			key;
	t_sprite		*sprites;
	double			*z_buffer;
	int				save;
	int				error;
}					t_game;

#endif
