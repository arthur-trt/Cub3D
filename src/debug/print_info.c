/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:50:54 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/25 12:12:56 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

#ifdef DEBUG
#define BIN_PATTERN "%c%c%c%c%c%c%c%c"
#define B_TO_B(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

static void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

void	ft_print_info(t_game game)
{
	int	i;

	ft_printf("\n-- MLX --\n");
	printf("win.mlx_ptr : %p\n", game.win.mlx_ptr);
	ft_printf("\n-- GAME --\n");
	ft_printf("game.save : %d\n", game.save);
	ft_printf("\n-- WIN --\n");
	printf("Resolution : %f\t%f\n", game.win.size.x, game.win.size.y);
	ft_printf("\n-- IMG --\n");
	printf("img.bpp : %d\n", game.win.img.bpp);
	printf("img.size_line : %d\n", game.win.img.size_line);
	printf("img.endian : %d\n", game.win.img.endian);
	printf("img.width : %d\n", game.win.img.width);
	printf("img.height : %d\n", game.win.img.height);
	ft_printf("\n-- PLAYER --\n");
	printf("player.pos.x : %f\n", game.player.pos.x);
	printf("player.pos.y : %f\n", game.player.pos.y);
	printf("player.dir.x : %f\n", game.player.dir.x);
	printf("player.dir.y : %f\n", game.player.dir.y);
	ft_printf("player.start_dir : %c\n", game.player.start_dir);
	ft_printf("\n-- TEXTURE --\n");
	printf("filename.north = %s\n", game.texture.file_north);
	printf("filename.south = %s\n", game.texture.file_south);
	printf("filename.east = %s\n", game.texture.file_east);
	printf("filename.west = %s\n", game.texture.file_west);
	printf("filename.sprite = %s\n", game.texture.file_sprite);
	printf("texture.floor =\t");
	printBits(sizeof( game.texture.floor), &game.texture.floor);
	printf("texture.cell =\t");
	printBits(sizeof( game.texture.cell), &game.texture.cell);
	ft_printf("\n-- MAP --\n");
	ft_printf("game.map.filename : %s\n", game.map.filename);
	printf("game.map.size.x : %f\n", game.map.size.x);
	printf("game.map.size.y : %f\n", game.map.size.y);
	printf("game.map.map :\n");
	i = 0;
	while (i < game.map.size.y)
	{
		ft_printf("%s\n", game.map.map[i]);
		i++;
	}
}

void	ft_print_sprite(t_sprite *s)
{
	t_sprite	*tmp;

	tmp = s;
	if (s)
	{
		printf("\n\n\nNEW LIST");
		while (tmp)
		{
			printf("\nLIST ITEM !\n");
			printf("s->dist : %lf\n", tmp->dist);
			printf("s->map_x : %d\n", tmp->map_x);
			printf("s->map_y : %d\n", tmp->map_y);
			tmp = tmp->next;
		}
	}
}

#endif
