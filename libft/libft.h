/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:49:04 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/05/15 23:57:34 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define FD_MAX 65534
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_var
{
	int		len;
	va_list	arg;
}				t_var;

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
void	ft_printf_c(t_var *var);
void	ft_printf_s(t_var *var);
void	ft_printf_p(t_var *var);
void	ft_printf_di(t_var *var);
void	ft_printf_ux(char c, int base, t_var *var);
void	ft_putchar(char c);
int		ft_nlen(int n, int base);
int		ft_unlen(unsigned long long n, int base);
void	ft_putnbr(int n);
void	ft_putnbr_base(unsigned long long n, int base, char *radix);

#endif
