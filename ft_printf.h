/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:45:12 by abchaban          #+#    #+#             */
/*   Updated: 2022/11/17 18:46:47 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putnbr_base(int nbr, char *base);
int		ft_putnbr_u(unsigned int n);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int n);

#endif