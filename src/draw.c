/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:19:15 by mkok              #+#    #+#             */
/*   Updated: 2017/03/21 15:00:04 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline(int x0, int y0, int x1, int y1, g_prop *global_prop)
{
	draw_prop	draw;

	draw.dx = abs(x1 - x0);
	draw.sx = x0 < x1 ? 1 : -1;
	draw.dy = abs(y1 - y0);
	draw.sy = y0 < y1 ? 1 : -1;
	draw.err = (draw.dx > draw.dy ? draw.dx : -(draw.dy)) / 2;
	draw.color = ft_htoi("0xFF0000");
	while (1)
	{
		mlx_pixel_put((*global_prop).mlx, (*global_prop).win, x0, y0, draw.color);
		if (x0 == x1 && y0 == y1)
			break;
		draw.er2 = draw.err;
		if (draw.er2 > -(draw.dx))
		{
			draw.err -= draw.dy;
			x0 += draw.sx;
		}
		if (draw.er2 < draw.dy)
		{
			draw.err += draw.dx;
			y0 += draw.sy;
		}
	}
}

void	draw_row(c_list *map, g_prop *global_prop)
{
	c_list		*one;
	c_list		*two;
	int			width;

	width = (*global_prop).width;
	one = map;
	two = (*map).next;
	while (width-- != 1)
	{
		drawline((*one).i, (*one).j, (*two).i, (*two).j, global_prop);
		one = two;
		two = (*two).next;
	}
}

void	draw_all_rows(c_list *map, g_prop *global_prop)
{
	int		height;
	c_list	*cmap;
	int		count;

	count = 0;
	cmap = map;
	height = 0;
	while (height++ != ((*global_prop).height))
	{
		draw_row(cmap, global_prop);
		cmap = map;
		cmap = lst_iter(cmap, (height * (*global_prop).width));
	}
}

void	draw_col(c_list *map, g_prop *global_prop)
{
	c_list		*one;
	c_list		*two;
	int			height;

	height = (*global_prop).height;
	one = map;
	two = lst_iter(map, (*global_prop).width);
	while (height-- != 1)
	{
		drawline((*one).i, (*one).j, (*two).i, (*two).j, global_prop);
		one = two;
		two = (lst_iter(two, (*global_prop).width));
	}
}

void	draw_all_cols(c_list *map, g_prop *global_prop)
{
	int		width;
	c_list	*cmap;
	int		count;

	count = 0;
	cmap = map;
	width = 0;
	while (width++ != (*global_prop).width)
	{
		draw_col(cmap, global_prop);
		cmap = map;
		cmap = lst_iter(cmap, width);
	}
}
