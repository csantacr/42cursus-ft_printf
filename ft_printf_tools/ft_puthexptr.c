#include "ft_printf_tools.h"

int	ft_puthexptr(unsigned long ptr)
{
	int		cc;

	cc = 0;
	cc += ft_putstr("0x");
	if (ptr == 0)
		cc += ft_putchar('0');
	else
		cc += ft_putlonghex(ptr, "0123456789abcdef");
	return (cc);
}
