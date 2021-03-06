/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_icount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:19:05 by mkok              #+#    #+#             */
/*   Updated: 2016/12/05 18:13:26 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_icount(int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		count++;
		n = n * -1;
	}
	if (n == 0 || n == -0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
