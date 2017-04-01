/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:18:41 by mkok              #+#    #+#             */
/*   Updated: 2017/03/02 15:22:56 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*get_correct_file(t_list **file, int fd)
{
	t_list			*temp;

	temp = *file;
	while (temp)
	{
		if ((int)(*temp).content_size == fd)
			return (temp);
		temp = (*temp).next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(file, temp);
	temp = *file;
	return (temp);
}

int					get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static t_list	*file;
	int				i;
	int				ret;
	t_list			*current;
	char			*tmp;

	tmp = 0;
	if (line == NULL || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	current = get_correct_file(&file, fd);
	if (!(*line = ft_strnew(1)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		(*current).content = ft_strjoin((*current).content, buff);
		if (!(*current).content)
			return (-1);
		if (ft_strchr(buff, '\n'))
			break;
	}
	if (ret < BUFF_SIZE && !ft_strlen((*current).content))
		return (0);
	i = ft_copyuntil(line, (*current).content, '\n');
	if (i < (int)ft_strlen((*current).content))
		 (*current).content = (*current).content + (i + 1);
	else
		ft_strclr((*current).content);
	return (1);
}
