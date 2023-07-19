/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantacr <csantacr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:08:59 by csantacr          #+#    #+#             */
/*   Updated: 2022/11/19 19:26:35 by csantacr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int nb);
int		ft_putstr(char *str);
int		ft_puthex(unsigned int nb, char *base);
int		ft_putlonghex(unsigned long nb, char *base);
int		ft_puthexptr(unsigned long ptr);

#endif