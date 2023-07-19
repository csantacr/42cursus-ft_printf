/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:05:44 by csantacr          #+#    #+#             */
/*   Updated: 2023/07/19 12:11:03 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tools.h"

int	ft_puthexptr(unsigned long ptr)
{
	int		cc;

	cc = 0;
	if (!ptr)
		cc += ft_putstr(NULL_PTR_STR);
	else
	{
		cc += ft_putstr("0x");
		cc += ft_putlonghex(ptr, "0123456789abcdef");
	}
	return (cc);
}
