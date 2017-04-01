/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 10:38:53 by mkok              #+#    #+#             */
/*   Updated: 2017/03/24 09:47:30 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include "../mlx/mlx.h"

typedef struct			global_properties
{
	void				*mlx;
	void				*win;
	int					win_width;
	int					win_height;
	int					width;
	int					height;
	int					nbr_count;
	int					sqr_len;
}						g_prop;

typedef struct			coor_list
{
	int					x;
	int					y;
	int					z;
	int					order;
	int					i;
	int					j;
	struct coor_list	*next;
}						c_list;

typedef struct			coor
{
	int					x;
	int					y;
	int					z;
	int					order;
	int					nbr_count;
	c_list				*head;
	c_list				*new;
	int					*cmap;
}						poop;

typedef struct			draw_line_properties
{
	int					dx;
	int					sx;
	int					dy;
	int					sy;
	int					err;
	int					er2;
	int					color;
}						draw_prop;

char					*read_all(int fd, char *line);
int						*to_int_map(char *line);
c_list					*to_c_list(int *int_map, g_prop *global_prop);
c_list					*c_listnew(int x, int y, int z, int order);
void					c_listadd(c_list *alist, c_list *new);
c_list					*lst_iter(c_list *lsthead, int len);
int						find_width(char *line);
void					draw_line(int x0, int y0, int x1, int y1, g_prop *global_prop);
void					drawline(int x0, int y0, int x1, int y1, g_prop *global_prop);
void					draw_row(c_list *map, g_prop *global_prop);
void					draw_all_rows(c_list *map, g_prop *global_prop);
void					draw_col(c_list *map, g_prop *global_prop);
void					draw_all_cols(c_list *map, g_prop *global_prop);
void					draw_it_vert(c_list *map, g_prop *global_prop);
void					translate_z(c_list *lsthead);
int						validate(char *row);

int						ishex(char c);
int						ft_htoi(char *str);
int						getrawint(char c);
g_prop					*init_g_prop(int win_width, int win_height, char *line, int sqr_len);
void					init_co(poop *co, g_prop *global_prop);
void					increment_y(poop *co, g_prop *global_prop);
void					print_c_list(c_list *lsthead);

#endif
