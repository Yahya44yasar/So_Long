/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:26:11 by yyasar            #+#    #+#             */
/*   Updated: 2022/12/16 14:24:40 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexbas(unsigned long p)
{
	int	i;

	i = 0;
	while (p != 0)
	{
		p /= 16;
		i++;
	}
	return (i);
}

void	hexwrite(unsigned long long p)
{
	if (p >= 16)
	{
		hexwrite(p / 16);
		hexwrite(p % 16);
	}
	else
	{
		if (p > 9)
			ft_putchar(p - 10 + 'a');
		else
			ft_putchar(p + '0');
	}
}

int	ft_ptr(unsigned long long p)
{
	int		i;

	i = ft_putstr("0x");
	if (p == 0)
		i += ft_putchar('0');
	else
	{
		hexwrite(p);
		i += hexbas(p);
	}
	return (i);
}
