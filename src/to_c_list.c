/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_c_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:20:15 by mkok              #+#    #+#             */
/*   Updated: 2017/03/24 10:06:38 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

c_list		*c_listnew(int x, int y, int z, int order)
{
	c_list	*newlist;

	if (!(newlist = (c_list *)malloc(sizeof(c_list))))
		return (NULL);
	(*newlist).x = x;
	(*newlist).y = y;
	(*newlist).z = z;
	(*newlist).order = order;
	(*newlist).i = 0;
	(*newlist).j = 0;
	(*newlist).next = NULL;
	return (newlist);
}

c_list		*lst_iter(c_list *lst, int len)
{
	c_list	*clst;
	int		count;

	count = 0;
	clst = lst;
	while ((*clst).next != 0)
	{
		if (count == len)
			return (clst);
		clst = (*clst).next;
		count++;
	}
	return (0);
}

void		c_listadd(c_list *alst, c_list *new)
{
	c_list		*current;

	current = alst;
	while ((*current).next != 0)
		current = (*current).next;
	(*current).next = new;
}

c_list		*to_c_list(int *int_map, g_prop *global_prop)
{
	poop			*co;

	if (!(co = (poop*)malloc(sizeof(poop))))
		return (NULL);	
	(*co).nbr_count = (*global_prop).nbr_count;
	(*co).cmap = int_map;
	init_co(co, global_prop);
	(*co).z = *(*co).cmap++;
	(*co).head = c_listnew((*co).x, (*co).y , (*co).z, (*co).order++);
	(*co).x = (*co).x + (*global_prop).sqr_len;
	increment_y(co, global_prop);
	while ((*co).nbr_count-- > 0)
	{
		(*co).z = *(*co).cmap++;
		(*co).new = c_listnew((*co).x, (*co).y , (*co).z, (*co).order++);
		(*co).x = (*co).x + (*global_prop).sqr_len;
		if ((*co).x >= (*global_prop).width * (*global_prop).sqr_len)
		{
			(*co).x = 0;
			(*co).y = (*co).y + (*global_prop).sqr_len;
		}
		c_listadd((*co).head, (*co).new);
	}
	return ((*co).head);
}
