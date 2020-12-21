/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:49:38 by atrouill          #+#    #+#             */
/*   Updated: 2020/11/13 11:49:43 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_color_to_px(t_window *w, int x, int y, int color)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	w->img.data[y * w->img.size_line + x * w->img.bpp / 8] = r;
	w->img.data[y * w->img.size_line + x * w->img.bpp / 8 + 1] = g;
	w->img.data[y * w->img.size_line + x * w->img.bpp / 8 + 2] = b;
}
