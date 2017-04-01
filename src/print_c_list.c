#include "fdf.h"

void		print_c_list(c_list *lsthead)
{
	c_list		*cur;

	cur = lsthead;
	while ((*cur).next != 0)
	{
		printf("ORDER %i\nx: %i\ny: %i\nz: %i\n", (*cur).order, (*cur).x, (*cur).y, (*cur).z);
		cur = (*cur).next;
	}
}
