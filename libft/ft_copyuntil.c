/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyuntil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 13:34:04 by mkok              #+#    #+#             */
/*   Updated: 2017/03/01 10:44:31 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_copyuntil(char **dst, char *src, char c)
{
	int		count;
	int		pos;
//	char	**tdst;

//	tdst = dst;
	pos = ft_strdlen(src, c);
	count = 0;
	if (!(*dst = ft_strnew(pos)))
		return (0);
	while (src[count] && count < pos)
	{
		if (!(*dst = ft_strjoinch(*dst, src[count])))
			return (0);
		count++;
	}
//	free (tdst);
	return (pos);
}
