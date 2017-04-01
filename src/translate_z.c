/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:35:07 by mkok              #+#    #+#             */
/*   Updated: 2017/03/21 14:53:13 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_z(c_list *lsthead)
{
	c_list		*clst;

	clst = lsthead;
	while ((*clst).next != 0)
	{
		(*clst).i = (*clst).x * cos(-0.8) - (*clst).y * sin(-0.8);
		(*clst).j = ((*clst).x * sin(-0.8) + (*clst).y * cos(-0.8))/ 2 + 500 - (*clst).z * 4;
		clst = (*clst).next;
	}
}
