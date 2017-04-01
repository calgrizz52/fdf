/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 09:48:05 by mkok              #+#    #+#             */
/*   Updated: 2017/02/27 17:12:17 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	char const 	*cs1;
	char const 	*cs2;
	int			count;

	cs1 = s1;
	cs2 = s2;
	count = 0;
	str = NULL;
	if (s1 == NULL || s2 == NULL)
		return (str);
	str = (char *)malloc(sizeof(char) * (ft_strlen(cs1) + ft_strlen(cs2) + 1));
	if (str == NULL)
		return (str);
	while (*cs1)
	{
		*str++ = *cs1++;
		count++;
	}
	while (*cs2)
	{
		*str++ = *cs2++;
		count++;
	}
	*str = '\0';
	return (str - count);
}
