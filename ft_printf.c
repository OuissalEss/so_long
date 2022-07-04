/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:49:01 by oessamdi          #+#    #+#             */
/*   Updated: 2022/02/15 11:33:10 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_printarg(va_list args, const char *str, int *i, int *nb)
{
	(*i)++;
	if (str[*i] == 'c')
		ft_putchar(va_arg(args, int), nb);
	else if (str[*i] == 's')
		ft_putstr(va_arg(args, char *), nb);
	else if (str[*i] == 'd')
		ft_putnbr(va_arg(args, int), nb);
	else if (str[*i] == 'i')
		ft_putnbr(va_arg(args, int), nb);
	else if (str[*i] == 'u')
		ft_putnbrbase(va_arg(args, unsigned int), "0123456789", nb);
	else if (str[*i] == '%')
		ft_putchar('%', nb);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		nb_print;

	i = 0;
	nb_print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_printarg(args, str, &i, &nb_print);
		else
			ft_putchar(str[i], &nb_print);
		i++;
	}
	va_end(args);
	return (nb_print);
}
