/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:19:11 by abchaban          #+#    #+#             */
/*   Updated: 2022/11/17 16:27:24 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_min(void)
{
	write(1, "-2147483648", 11);
	return (11);
}

int	ft_putnbr(int n)
{
	int	len;
	int	nbis;

	nbis = n;
	len = 0;
	if (n == 0)
		len++;
	if (n == -2147483648)
		return (handle_min());
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		nbis = nbis * -1;
		len++;
	}
	if (n > 9)
		ft_putnbr((n / 10));
	while (nbis > 0)
	{
		nbis = nbis / 10;
		len++;
	}
	ft_putchar(((n % 10) + 48));
	return ((len));
}
