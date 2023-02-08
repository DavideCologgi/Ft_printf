/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:41:38 by dcologgi          #+#    #+#             */
/*   Updated: 2023/02/08 15:40:46 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(uintptr_t p)
{
	int	i;

	i = 0;
	while (p != 0)
	{
		i++;
		p = p / 16;
	}
	return (i);
}

void	ft_printptr(uintptr_t p)
{
	if (p >= 16)
	{
		ft_putptr(p / 16);
		ft_putptr(p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar(p + '0');
		else
			ft_putchar(p - 10 + 'a');
	}
}

int	ft_putptr(uintptr_t ptr)
{
	int	char_stampato;

	char_stampato = 0;
	char_stampato += write(1, "0x", 2);
	if (ptr == 0)
		char_stampato += write(1, "0", 1);
	else
	{
		ft_printptr(ptr);
		char_stampato += ft_ptrlen(ptr);
	}
	return (char_stampato);
}
