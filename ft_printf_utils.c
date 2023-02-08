/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:54:29 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/08 14:46:48 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(non valido)");
		return (12);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	lenght(int nb, int base)
{
	int i;

	i = 0;
	if (nb <= 0)
		++i;
	while (nb && ++i)
		nb /= base;
	return (i);
}

int ll_lenght(long long nb, int base)
{
	int	i;

	i = 0;
	if (nb <= 0)
		++i;
	while (nb && ++i)
		nb /= base;
	return (i);
}
