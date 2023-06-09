/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:34:04 by yyasar            #+#    #+#             */
/*   Updated: 2022/12/16 14:32:07 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexabas(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

void	ft_printhexa(char c, unsigned int n)
{
	if (n >= 16)
	{
		ft_printhexa(c, n / 16);
		ft_printhexa(c, n % 16);
	}
	else if (n <= 9)
		ft_putchar(n + 48);
	else if (c == 'x' && n >= 10 && n <= 15)
		ft_putchar(n + 87);
	else if (c == 'X' && n >= 10 && n <= 15)
		ft_putchar(n + 55);
}

int	ft_hexa(char c, unsigned int nbr)
{
	int	i;

	i = ft_hexabas(nbr);
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	ft_printhexa(c, nbr);
	return (i);
}
