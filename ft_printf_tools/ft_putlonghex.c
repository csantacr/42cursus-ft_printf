#include "ft_printf_tools.h"

int	ft_putlonghex(unsigned long nb, char *base)
{
	int	cc;
	int	nb_hex[40];
	int	i;

	cc = 0;
	if (!nb)
		cc += ft_putchar('0');
	i = 0;
	while (nb)
	{
		nb_hex[i] = nb % 16;
		nb /= 16;
		i++;
	}
	while (--i >= 0)
		cc += ft_putchar(base[nb_hex[i]]);
	return (cc);
}
