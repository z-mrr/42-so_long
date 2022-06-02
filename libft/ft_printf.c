/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:41:32 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/05/15 17:22:47 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_conversion(char *str, t_var *var)
{
	if (*str == 'c')
		ft_printf_c(var);
	else if (*str == 's')
		ft_printf_s(var);
	else if (*str == 'p')
		ft_printf_p(var);
	else if (*str == 'd' || *str == 'i')
		ft_printf_di(var);
	else if (*str == 'u')
		ft_printf_ux(*str, 10, var);
	else if (*str == 'x' || *str == 'X')
		ft_printf_ux(*str, 16, var);
	else if (*str == '%')
	{
		write(1, str, 1);
		var->len++;
	}
	return (str + 1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	t_var	var;

	va_start(var.arg, format);
	var.len = 0;
	len = 0;
	while (*format)
	{
		if (*format == '%')
			format = ft_conversion((char *)format + 1, &var);
		else if (*format)
		{
			write(1, format, 1);
			format++;
			len++;
		}
	}
	va_end(var.arg);
	return (len + var.len);
}
/*
#include <stdio.h>

int	main(void)
{
	int		a, b, d = 500;
	int	*c = &d;

	a =    printf("aaa: %u, %u\n", 0, 0);
	b = ft_printf("aaa: %u, %u\n", 0, 0);
	printf("%d\n", a);
	printf("%d\n", b);

	return (0);
}
*/
