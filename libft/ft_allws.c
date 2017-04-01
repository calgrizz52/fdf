/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 21:13:42 by mkok              #+#    #+#             */
/*   Updated: 2016/12/10 21:33:01 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_allws(const char *str)
{
	while (*str)
	{
		if (*str != '\n' && *str != '\t' && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}
