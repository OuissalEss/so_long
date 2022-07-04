/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:31:28 by oessamdi          #+#    #+#             */
/*   Updated: 2022/02/15 11:32:31 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c, int *nb_print)
{
	write(1, &c, 1);
	(*nb_print) += 1;
}

void	ft_putnbr(int n, int *nb)
{
	if (n == -2147483648)
	{
		ft_putnbr(n / 10, nb);
		ft_putchar('8', nb);
	}
	else if (n < 0)
	{
		ft_putchar('-', nb);
		ft_putnbr(n * -1, nb);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, nb);
		ft_putchar(n % 10 + '0', nb);
	}
}

void	ft_putnb(unsigned int nb, const char *base, int *n)
{
	int	lb;

	lb = ft_strlen(base);
	if (nb > 0)
	{
		ft_putnb(nb / lb, base, n);
		ft_putchar(base[nb % lb], n);
	}
}

void	ft_putnbrbase(unsigned int nb, const char *base, int *n)
{
	if (nb == 0)
		ft_putchar('0', n);
	else
		ft_putnb(nb, base, n);
}

void	ft_putstr(char *s, int *np)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*np += 6;
	}
	else
		while (*s)
			ft_putchar(*s++, np);
}
