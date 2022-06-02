/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:33:19 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/05/15 17:22:53 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_c(t_var *var)
{
	char	c;

	c = va_arg(var->arg, int);
	write(1, &c, 1);
	var->len++;
}

void	ft_printf_s(t_var *var)
{
	char	*str;

	str = va_arg(var->arg, char *);
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		str++;
		var->len++;
	}
}

void	ft_printf_p(t_var *var)
{
	long long	n;

	n = va_arg(var->arg, long long);
	if (!n)
	{
		write (1, "0x0", 3);
		var->len += 3;
		return ;
	}
	var->len += ft_unlen(n, 16) + 2;
	write(1, "0x", 2);
	ft_putnbr_base(n, 16, "0123456789abcdef");
}

void	ft_printf_di(t_var *var)
{
	int	n;

	n = va_arg(var->arg, int);
	var->len += ft_nlen(n, 10);
	ft_putnbr(n);
}

void	ft_printf_ux(char c, int base, t_var *var)
{
	unsigned int	n;

	n = va_arg(var->arg, unsigned int);
	if (!n)
	{
		write(1, "0", 1);
		var->len++;
		return ;
	}
	var->len += ft_unlen(n, base);
	if (c == 'X')
		ft_putnbr_base(n, base, "0123456789ABCDEF");
	else
		ft_putnbr_base(n, base, "0123456789abcdef");
}
