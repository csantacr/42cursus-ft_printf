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
#include "libft.h"
#include <stdio.h>

int	print_item(char type, char *str, va_list ap, int cc)
{
	printf("\n---print_item---\n");
	printf("tipo: %c\n", type);
	if (type == 'l') // l = literal
		cc += write(1, str, 1);
	else if (type == 'c')
		cc += ft_putchar(va_arg(ap, int));
	else if (type == 's')
		cc += ft_putstr(va_arg(ap, char *));
	else if (type == 'i')
		cc += ft_putnbr(va_arg(ap, int));
	printf("\n///print_item///\n");
	return (cc);
}

int	ft_printf(char const *str, ...)
{
	int		cc;
	va_list	ap;

	cc = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%') // si no hay tipo, pasar tipo nulo/literal
			print_item('l', (char *) str, ap, cc);
		else // si hay tipo, print
			print_item(*(str + 1), (char *) str, ap, cc);
		str++;
	}
	va_end(ap);
	return (cc);
}

int main(void)
{
	char c = 'd';
	char c2 = 'g';
	char *str = "hola";
	
	printf("return: %d\n", ft_printf("ab%sc%cef%c\n", str, c, c2));
	return (0);
}
