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
#include <stdio.h>

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static void ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	print_item(char type, char *str, va_list ap)
{
	printf("\n---print_item---\n");
	printf("tipo: %c\n", type);
	if (type == 'l') // l = literal
		write(1, str, 1);
	else if(type == 'c')
		ft_putchar(va_arg(ap, int));
	else if(type == 's')
		ft_putstr(va_arg(ap, char *));
	printf("\n///print_item///\n");
}

int	ft_printf(char const *str, ...)
{
	va_list ap;
	
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%') // si no hay tipo, pasar tipo nulo/literal
			print_item('l', (char *) str, ap);
		else // si hay tipo, print
			print_item(*(str + 1), (char *) str, ap);
		str++;
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	char c = 'd';
	char c2 = 'g';
	char *str = "hola";
	
	ft_printf("ab%sc%cef%c\n", str, c, c2);
	return (0);
}
