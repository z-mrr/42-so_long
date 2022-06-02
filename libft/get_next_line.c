/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:12:12 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/05/15 17:22:59 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_pos(char const *s, char c)
{
	size_t	i;

	i = 1;
	while (*s)
	{
		if (*s == c)
			return (i);
		i++;
		s++;
	}
	return (0);
}

void	ft_read(int fd, char *buffer, char **str)
{
	char	*temp;
	int		r;

	if (!str[fd] || !ft_pos(str[fd], '\n'))
	{
		r = read(fd, buffer, BUFFER_SIZE);
		while (r > 0)
		{
			buffer[r] = '\0';
			if (!str[fd])
				str[fd] = ft_strdup(buffer);
			else
			{
				temp = str[fd];
				str[fd] = ft_strjoin(str[fd], buffer);
				free (temp);
			}
			if (ft_pos(buffer, '\n'))
				break ;
			r = read(fd, buffer, BUFFER_SIZE);
		}
	}
	free (buffer);
}

char	*ft_line(int fd, char **str)
{
	char			*res;
	char			*temp;
	unsigned int	pos;
	unsigned int	len;

	if (!str[fd])
		return (0);
	pos = ft_pos(str[fd], '\n');
	if (!pos)
	{
		res = ft_strdup(str[fd]);
		free (str[fd]);
		str[fd] = 0;
		return (res);
	}
	len = ft_strlen(str[fd]);
	res = ft_substr(str[fd], 0, pos);
	temp = str[fd];
	if (len == pos)
		str[fd] = 0;
	else
		str[fd] = ft_substr(str[fd], pos, len - (pos - 1));
	free(temp);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str[FD_MAX];

	buffer = malloc (BUFFER_SIZE + 1);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buffer, 0) == -1 || !buffer)
	{
		free (buffer);
		return (0);
	}
	ft_read(fd, buffer, str);
	return (ft_line(fd, str));
}
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
//	int		n;

	fd = open("42", O_RDONLY);
	if (fd == -1)
	{
		printf("Open error\n");
		return (1);
	}
//	n = -1;
//	while (++n < 7)
			printf("gnl:%s\n", get_next_line(fd));
	return (0);
}
*/
