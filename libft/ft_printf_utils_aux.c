/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:34:21 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/05/15 17:22:25 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_nlen(int n, int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n && ++i)
		n /= base;
	return (i);
}

int	ft_unlen(unsigned long long n, int base)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n && ++i)
		n /= base;
	return (i);
}

void	ft_putnbr(int n)
{
	int		i;
	int		nbr[11];

	if (n == -2147483648 || n == 0)
	{
		if (n == -2147483648)
			write(1, "-2147483648", 11);
		else if (n == 0)
			ft_putchar('0');
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		nbr[i] = n % 10;
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(nbr[i] + '0');
}

void	ft_putnbr_base(unsigned long long n, int base, char *radix)
{
	int		i;
	int		tab[21];

	i = 0;
	while (n)
	{
		tab[i] = n % base;
		n /= base;
		i++;
	}
	while (--i >= 0)
		ft_putchar(radix[tab[i]]);
}
