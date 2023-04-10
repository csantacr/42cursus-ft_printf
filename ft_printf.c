/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:25:56 by csantacr          #+#    #+#             */
/*   Updated: 2023/03/23 21:25:06 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdarg.h>

void print_item(char* type, char *str)
{
	if (ft_strncmp(type, "literal", 8) == 0)
		write(1, str, 1);
	else if(ft_strncmp(type, "c", 1))
		write(1, str, 1);
}

int	ft_printf(char const *str, ...)
{
	va_list args;
	int		i;
	char	segundo;
	//int		len;

	va_start(args, str);
	while (*str)
	{
		if (*str != '%') // si no hay tipo, pasar tipo nulo/literal
			print_item("literal", str);
		else // si hay tipo, print
			print_item(*(str + 1), str);
		str++;
	}
	i = 1;
	while (i)
	{
		segundo = va_arg(args, int);
		i--;
	}
	va_end(args);
	return (0);
}

int main(void)
{
	char c = 'd';
	char c2 = 'g';
	
	ft_printf("abc%cef%c\n", c, c2);
	return (0);
}
