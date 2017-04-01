/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:58:41 by mkok              #+#    #+#             */
/*   Updated: 2016/12/11 18:28:25 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char		*u1;
	const char	*u2;

	u1 = s1;
	u2 = s2;
	while (*u1 != '\0')
		u1++;
	while (*u2 != '\0')
	{
		*u1 = *u2;
		u1++;
		u2++;
	}
	*u1 = '\0';
	return (s1);
}