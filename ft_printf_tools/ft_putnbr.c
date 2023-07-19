/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:05:52 by csantacr          #+#    #+#             */
/*   Updated: 2023/07/19 12:05:52 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tools.h"

int	ft_putnbr(int nb)
{
	unsigned int	unb;

	unb = 0;
	if (nb == -2147483648)
	{
		unb += ft_putnbr(-214748364);
		unb += ft_putchar('8');
	}
	else if (nb < 0)
	{
		unb += ft_putchar('-');
		unb += ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
			unb += ft_putnbr(nb / 10);
		unb += ft_putchar((nb % 10) + '0');
	}
	return (unb);
}
