#include "guimp.h"

int			ft_strlen(const char *src)
{
	int		i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void		ft_putstr(char const *str, int new_str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
	if (new_str)
		write(1, "\n", 1);
}

void		ft_error(const char *error)
{
	ft_putstr("\033[31m", 0);
	ft_putstr(error, 0);
	ft_putstr("\033[0m", 1);
	exit(1);
}