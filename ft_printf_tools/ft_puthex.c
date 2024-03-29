/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:05:37 by csantacr          #+#    #+#             */
/*   Updated: 2023/07/19 12:05:37 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tools.h"

int	ft_puthex(unsigned int nb, char *base)
{
	int	cc;
	int	nb_hex[20];
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
