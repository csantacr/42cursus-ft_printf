#include "ft_printf_tools.h"

int	ft_putstr(char *str)
{
	int	bc;

	bc = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		bc++;
	}
	return (bc);
}
