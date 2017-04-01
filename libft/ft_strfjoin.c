/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:24:36 by mkok              #+#    #+#             */
/*   Updated: 2017/02/24 09:26:19 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char *s1, char *s2, int free)
{
	char		*str;
	int			len;
	int			count;

	count = ft_strlen(s1) + ft_strlen(s2);
	str = NULL;
	if (s1 == NULL || s2 == NULL)
		return (str);
	if (!(str = (char *)malloc(sizeof(char) * count + 1)))
		return (str);
	len = ft_strlen(s1);
	ft_memmove(str, s1, len);
	str += len;
	len = ft_strlen(s2);
	ft_memmove(str, s2, len);
	str += len;
	*str = '\0';
	if (free == 1)
		ft_strdel(&s1);
	else if (free == 2)
		ft_strdel(&s2);
	else if (free == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str - count);
}
