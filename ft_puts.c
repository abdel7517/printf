/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:13:23 by abchaban          #+#    #+#             */
/*   Updated: 2022/11/17 16:43:54 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_min(void)
{
	write(1, "0", 1);
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int			size_base;
	int			nbr_final[100];
	int			i;
	long		nb;
	int			len;

	nb = nbr;
	i = 0;
	size_base = 0;
	if (nbr == 0)
		return (handle_min());
	if (nb < 0)
		nb = nb + 4294967296;
	while (base[size_base])
		size_base++;
	while (nb)
	{
		nbr_final[i] = nb % size_base;
		nb = nb / size_base;
		i++;
	}
	len = i;
	while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
	return (len);
}

int	ft_putnbr_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n > 9)
	{
		ft_putnbr_u((n / 10));
	}
	ft_putchar(((n % 10) + 48));
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
	{
		while (*str)
		{
			write(1, str++, 1);
			i++;
		}
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
