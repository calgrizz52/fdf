/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 10:38:12 by mkok              #+#    #+#             */
/*   Updated: 2017/03/24 10:14:31 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		my_key_funct(int keycode)
{
	ft_putstr("Key event:\n");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
		exit (0);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		*int_map;
	c_list	*map;
	c_list	*maphead;
	g_prop	*global_prop;
	int		nbr_count;

	nbr_count = 0;
	line = NULL;
	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(line = ft_strnew(1)))
			return (-1);
		if ((line = read_all(fd, line)))
		{
			// Validate file
			if (!(nbr_count = validate(line)))
			{
				printf("YOU FILE SUCKS\nGET A NEW ONE!!!\n");
				return (0);
			}
			if (!(global_prop = init_g_prop(1920, 1080, line, 7)))
				return (-1);
			int_map = to_int_map(line);
			map = to_c_list(int_map, global_prop);
			maphead = map;
		 	translate_z(map);

			// Draw something
			draw_all_cols(map, global_prop);
			draw_all_rows(map, global_prop);
			mlx_key_hook((*global_prop).win, my_key_funct, (*global_prop).mlx);
			mlx_loop((*global_prop).mlx);

		}
	}
	else
	{
		ft_putstr("Provide only one map file (.fdf)\n");
		return (0);
	}
	if (argc == 2)
		close (fd);
}
