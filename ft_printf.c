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

/*
- %c Imprime un solo carácter.
- %s Imprime una string (como se define por defecto en C).
• %p El puntero void * dado como argumento se imprime en formato hexadecimal.
- %d Imprime un número decimal (base 10).
- %i Imprime un entero en base 10.
- %u Imprime un número decimal (base 10) sin signo.
• %x Imprime un número hexadecimal (base 16) en minúsculas.
• %X Imprime un número hexadecimal (base 16) en mayúsculas.
- % % para imprimir el símbolo del porcentaje.
*/

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
	else if (type == 'd' || type == 'i')
		cc += ft_putnbr(va_arg(ap, int));
	else if (type == 'u')
		cc += ft_putunbr(va_arg(ap, unsigned int));
	else if (type == '%')
		cc += ft_putunbr(va_arg(ap, unsigned int));
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
			print_item(*str, (char *) str, ap, cc);
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
	unsigned int un = 4294967294;

	printf("ft: %d\n", ft_printf("ab%sc%u%%c%cef%c\n", str, un, c, c2));
	printf("og: %d\n", printf("ab%sc%u%%c%cef%c\n", str, un, c, c2));
	return (0);
}
