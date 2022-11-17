/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:05:39 by abchaban          #+#    #+#             */
/*   Updated: 2022/11/17 14:06:03 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>


int	ft_printf(const char*, ...);
int	ft_putnbr_base(int nbr, char *base);
int	ft_putnbr_u(unsigned int n);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int n);
#endif