/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:05:57 by csantacr          #+#    #+#             */
/*   Updated: 2023/07/19 12:05:57 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tools.h"

int	ft_putunbr(unsigned int nb)
{
	int	bc;

	bc = 0;
	if (nb > 9)
		bc += ft_putunbr(nb / 10);
	bc += ft_putchar((nb % 10) + '0');
	return (bc);
}
