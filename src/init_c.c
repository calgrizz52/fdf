#include "fdf.h"

void		init_co(poop *co, g_prop *global_prop)
{
	(*co).x = 0;
	(*co).y = ((*global_prop).win_height / 4);
	(*co).order = 0;
}

void		increment_y(poop *co, g_prop *global_prop)
{
	if ((*co).order >= (*global_prop).width)
		(*co).y = (*co).y + (*global_prop).sqr_len;
}
