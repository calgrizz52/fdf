#include "fdf.h"

int		ishex(char c)
{
	if (c >= 'A' && c <= 'F')
	{
		return (1);
	}
	else
		return (0);
}

int		getrawint(char c)
{
	int			i;

	i = 0;
	if (ishex(c))
		return (c - 'A' + 10);
	else
		return (c - '0');
}

int		ft_htoi(char *str)
{
	int			res;
	int			i;
	int			power;

	res = 0;
	power = 1;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		res = res + getrawint(str[i]) * power;
		power = power * 16;
		i--;
	}
	return (res);
}
