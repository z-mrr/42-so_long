/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:57:58 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/05/29 12:45:48 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_player(t_game *game, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	if (!game->over)
		img_to_window(game, game->img_player, x, y);
	else
		img_to_window(game, game->img_mid, x, y);
}

void	draw_exit(t_game *game, int x, int y)
{
	if (game->collect)
		img_to_window(game, game->img_exit, x, y);
	else
		img_to_window(game, game->img_exit2, x, y);
}

int	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				img_to_window(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				img_to_window(game, game->img_mid, x, y);
			else if (game->map[y][x] == 'E')
				draw_exit(game, x, y);
			else if (game->map[y][x] == 'P')
				draw_player(game, x, y);
			else if (game->map[y][x] == 'C')
				img_to_window(game, game->img_collect, x, y);
			else if (game->map[y][x] == 'X')
				img_to_window(game, game->img_foe, x, y);
		}
	}
	draw_text(*game);
	return (0);
}
