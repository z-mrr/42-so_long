/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:35:08 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/05/29 12:45:48 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_foe_map(t_game *game)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (game->map[i][j] == 'X')
				x++;
			j++;
		}
		i++;
	}
	if (x)
		return (1);
	return (0);
}

int	check_foe(char **map, int i, int j)
{
	int	x;

	x = 0;
	if (map[i][j] == '0')
	{
		if (map[i][j + 1] == '0')
			x++;
		if (map[i][j - 1] == '0')
			x++;
		if (map[i + 1][j] == '0')
			x++;
		if (map[i + 1][j + 1] == '0')
			x++;
		if (map[i + 1][j - 1] == '0')
			x++;
		if (map[i - 1][j] == '0')
			x++;
		if (map[i - 1][j - 1] == '0')
			x++;
		if (map[i - 1][j - 1] == '0')
			x++;
		if (x >= 5)
			return (1);
	}
	return (0);
}

void	generate_foe(t_game *game)
{
	int		i;
	int		j;

	if (game->map_h == 3)
	{
		if (game->map[2][game->map_w - 1] == '0')
			game->map[2][game->map_w - 1] = 'X';
		return ;
	}
	i = 1;
	while (game->map[i])
	{
		j = 1;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0' && check_foe(game->map, i, j))
			{
				game->map[i][j] = 'X';
				return ;
			}
			j++;
		}
		i++;
	}
}
