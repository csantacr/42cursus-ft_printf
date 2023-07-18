/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:25:56 by csantacr          #+#    #+#             */
/*   Updated: 2023/06/22 19:34:57 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_item(char type, const char *str, va_list ap)
{
	int	cc;

	cc = 0;
	if (type == 'l')
		cc += write(1, str, 1);
	else if (type == 'c')
		cc += ft_putchar(va_arg(ap, int));
	else if (type == 's')
		cc += ft_putstr(va_arg(ap, char *));
	else if (type == 'd' || type == 'i')
		cc += ft_putnbr(va_arg(ap, int));
	else if (type == 'u')
		cc += ft_putunbr(va_arg(ap, unsigned int));
	else if (type == 'x')
		cc += ft_puthex(va_arg(ap, int), "0123456789abcdef");
	else if (type == 'X')
		cc += ft_puthex(va_arg(ap, int), "0123456789ABCDEF");
	else if (type == '%')
		cc += ft_putchar('%');

	return (cc);
}

int	ft_printf(const char *str, ...)
{
	int		c_count;
	va_list	ap;

	c_count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
			c_count += print_item('l', str, ap);
		else
		{
			c_count += print_item(*(str + 1), str, ap);
			str++;
		}
		str++;
	}
	va_end(ap);
	return (c_count);
}

/* int main(void)
{
	char c = 'd';
	char c2 = 'g';
	char *str = "hola";
	void *ptr;

	ptr = 0;
	unsigned int un = 4294967294;
	int max_int = 2147483647;
	printf("ft: %d\n", ft_printf("ab%sc%u%%c%cef%c hex: %x\n", str, un, c, c2, max_int));
	printf("og: %d\n", printf("ab%sc%u%%c%cef%c hex: %x ptr: %p\n", str, un, c, c2, max_int, ptr));
	return (0);
} */
