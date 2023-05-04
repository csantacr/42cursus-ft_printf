/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:25:56 by csantacr          #+#    #+#             */
/*   Updated: 2023/04/10 19:40:17 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static void ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	print_item(char type, char *str)
{
	printf("\ntipo: %c\n", type);
	printf("---\n");
	if (type == 'l') // l = literal
		write(1, str, 1);
	else if(type == 'c')
	{
		write(1, "c", 1);
	}
	else if(type == 's')
	{
		ft_putstr(str + 1);
		
	}
	printf("\n///\n");
}

int	ft_printf(char const *str, ...)
{
	va_list ap;
	int		i;
	char	segundo;
	//int		len;
	
	va_start(ap, str);
	// printf("args: %c\n", args);
	while (*str)
	{
		if (*str != '%') // si no hay tipo, pasar tipo nulo/literal
			print_item('l', (char *) str);
		else // si hay tipo, print
			print_item(*(str + 1), (char *) str);
		str++;
	}
	i = 1;
	while (i)
	{
		segundo = va_arg(ap, char);
		printf("argumento: %c\n", segundo);
		i--;
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	char c = 'd';
	char c2 = 'g';
	
	ft_printf("abc%cef%c\n", c, c2);
	return (0);
}
