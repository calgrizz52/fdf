#include "fdf.h"

g_prop		*init_g_prop(int win_width, int win_height, char *line, int sqr_len)
{
	g_prop		*global_prop;

	if (!(global_prop = (g_prop*)malloc(sizeof(g_prop))))
		return (NULL);

	(*global_prop).mlx = mlx_init();
	(*global_prop).win = mlx_new_window((*global_prop).mlx, win_width, win_height, "FDF MANG");
	(*global_prop).win_width = win_width;
	(*global_prop).win_height = win_height;
	(*global_prop).width = find_width(line);
	(*global_prop).nbr_count = validate(line);
	(*global_prop).height = (*global_prop).nbr_count / (*global_prop).width;
	(*global_prop).sqr_len = sqr_len;
	return (global_prop);
}
