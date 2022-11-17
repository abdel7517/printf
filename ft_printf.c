/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:00 by abchaban          #+#    #+#             */
/*   Updated: 2022/11/17 16:54:09 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_uns(unsigned long nbr, char *base)
{
	int		size_base;
	int		nbr_final[100];
	int		i;
	int		len;

	i = 0;
	size_base = 0;
	if (nbr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	len = i;
	ft_putstr("0x");
	while (--i >= 0)
		ft_putchar(base[nbr_final[i]]);
	return (len + 2);
}

int	display(const char c, va_list ap)
{
	int	i;

	i = 0;
	if (c == 's')
		i = ft_putstr(va_arg(ap, char *));
	else if ((c == 'd' || c == 'i'))
		i = ft_putnbr(va_arg (ap, long int ));
	else if (c == 'c')
		i = ft_putchar(va_arg(ap, int));
	else if ((c == 'X'))
		i = ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
	else if ((c == 'p'))
		i = ft_putnbr_base_uns(va_arg(ap, unsigned long), "0123456789abcdef");
	else if (c == 'x')
		i = ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	else if (c == 'u')
		i = ft_putnbr_u(va_arg(ap, unsigned int));
	else if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	next_is_set(char c)
{
	char const	*set = "cspdiuxX%";
	int			i;

	i = 0;
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

int	check_param(const char *str, va_list ap)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (next_is_set(str[i + 1]))
			{
				i++;
				len += display(str[i], ap);
			}
			else
				len += ft_putchar(str[i]);
		}
		else
			len += ft_putchar(str[i]);
	i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			len;	

	va_start(ap, str);
	len = check_param(str, ap);
	va_end(ap);
	return (len);
}
