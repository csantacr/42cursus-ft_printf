/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:23:05 by csantacr          #+#    #+#             */
/*   Updated: 2023/07/19 12:27:26 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_TOOLS_H
# define FT_PRINTF_TOOLS_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_putstr(char *str);
int	ft_puthex(unsigned int nb, char *base);
int	ft_putlonghex(unsigned long nb, char *base);
int	ft_puthexptr(unsigned long ptr);

#endif