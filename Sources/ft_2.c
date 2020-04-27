#include "rt.h"

size_t				ft_strlen(const char *str)
{
	register size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
