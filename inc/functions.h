/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:19:00 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/16 09:28:03 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structures.h"

void	cub3d(t_game game);

/*
** PARSER
*/
int		ft_parse_args(t_game *game, int argc, char *argv[]);
int		parse_cub(t_game *g);
int		check_cub(t_game *g, int fd);
void	parse_informations(t_game *g, char *str);
t_coor	parse_resolution(char *str);
int		parse_color(char *str);
int		map_parser(t_map *map, t_player *p);
int		check_map(t_map *map, t_player *p, int fd);
void	line_to_array(char *map_line, char *file_line);

/*
** MANAGERS
*/
int		key_event(t_game *g);
int		key_pressed(int keycode, t_game *g);
int		key_released(int keycode, t_game *g);
int		destroy_win(t_game *g);
int		focus_out(t_game *g);

/*
** ENGINE
*/
int		launch_game(t_game *g);
int		main_loop(t_game *g);
void	dda(t_game *g);
void	move_up(t_player *p, t_map map);
void	move_down(t_player *p, t_map map);
void	move_right(t_player *p, t_map map);
void	move_left(t_player *p, t_map map);
void	rotate_left(t_player *p);
void	rotate_right(t_player *p);
void	calc_delta_dist(t_ray *ray);
void	calc_side_dist(t_ray *ray, t_player player);
void	get_perp(t_ray *r, t_player p, t_window w);
void	calc_ray(t_ray *ray, t_player *player, t_window win);
void	raycaster(t_game *game);
void	add_sprite(t_game *g);
void	sort_insert(t_sprite **sprite, t_sprite *new);

/*
** RENDERING
*/
void	bmp_header(t_img img, int fd);
void	bmp_info(t_img img, int fd);
void	bmp_img(t_img img, int fd);
int		bmp(t_game *g);
void	render_floor_cell(t_window *w, t_ray ray, t_texture t);
void	render_sprite(t_game *g);
void	copy_sprite_img(t_window *w, t_sprite *s, t_texture t, double *zbuffer);
void	copy_sprite_img_helper(t_window *w, t_sprite *s, t_texture t);
void	render_text(t_ray *r, t_texture *t, t_window *win, t_player p);
void	calc_wall(t_ray *r, t_texture *t, t_window *w);
void	copy_text_img(t_window *w, t_ray *r, t_img t);

/*
** TOOLS
*/
int		is_identifier(char *str);
void	put_color_to_px(t_window *w, int x, int y, int color);
void	puterr(char *str);
int		error(int ec);
int		open_file(char *filename);
int		close_file(int fd);
void	free_game(t_game *g);
void	free_texture(t_texture *t);
void	free_map(t_map *map);
void	free_splitted(char **split);
void	free_sprite(t_sprite **s);
void	init_game(t_game *g);
void	init_win(t_window *w);
void	init_img(t_img *i);
void	init_texture(t_texture *t);
void	init_map(t_map *m);
void	init_player(t_player *p);
void	init_keyboard(t_key *k);
void	init_player_dir(t_player *p);
void	init_ray(t_ray *r);
void	init_sprite(t_sprite *s);
int		is_map_line(char *str);
double	obtain_map_size(t_map map);
void	arrange_map_line(t_map *map);
int		verify_map(t_map map);
int		verify_player(t_map *map, t_player *p);
int		init_mlx(t_window *w);
int		init_mlx_screenshot(t_window *w);
int		init_image(t_window w, t_img *img);
void	update_screen(t_window *w);
int		check_no_duplicate(t_sprite *sprite, t_sprite *new);
void	sprite_transformation(t_sprite *s, t_player p, t_window w);
void	sprite_sizing(t_sprite *s, t_window w);
char	*ft_clean_str(char *str);
int		is_cub_file(char *filename);
int		load_texture(t_game *g);
int		load_texture_from_file(t_window w, t_img *t, char *filename);
void	set_coor(t_coor *c, double x, double y);
int		rgb_to_int(int red, int green, int blue);

#endif
