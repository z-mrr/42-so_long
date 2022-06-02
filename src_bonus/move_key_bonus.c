/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:07:31 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/05/25 17:52:58 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_w(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1'
		&& (game->map[game->player_y - 1][game->player_x]
		!= 'E' || !game->collect))
	{
		if (game->map[game->player_y - 1][game->player_x] == 'C')
		{
			game->collect--;
			game->map[game->player_y][game->player_x] = '0';
			game->player_y--;
			game->map[game->player_y][game->player_x] = 'P';
		}
		else if (game->map[game->player_y - 1][game->player_x] == '0')
		{
			game->map[game->player_y][game->player_x] = '0';
			game->player_y--;
			game->map[game->player_y][game->player_x] = 'P';
		}
		else
			game->over = 1;
		game->moves++;
		mlx_clear_window(game->mlx, game->win);
	}
	draw_map(game);
}

void	move_a(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "xpm/player_back.xpm", &game->img_w, &game->img_h);
	if (game->map[game->player_y][game->player_x - 1] != '1' && (
		game->map[game->player_y][game->player_x - 1] != 'E' || !game->collect))
	{
		if (game->map[game->player_y][game->player_x - 1] == 'C')
		{
			game->collect--;
			game->map[game->player_y][game->player_x] = '0';
			game->player_x--;
			game->map[game->player_y][game->player_x] = 'P';
		}
		else if (game->map[game->player_y][game->player_x - 1] == '0')
		{
			game->map[game->player_y][game->player_x] = '0';
			game->player_x--;
			game->map[game->player_y][game->player_x] = 'P';
		}
		else
			game->over = 1;
		game->moves++;
		mlx_clear_window(game->mlx, game->win);
	}
	draw_map(game);
}

void	move_s(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1'
		&& (game->map[game->player_y + 1][game->player_x] != 'E'
		|| !game->collect))
	{
		if (game->map[game->player_y + 1][game->player_x] == 'C')
		{
			game->collect--;
			game->map[game->player_y][game->player_x] = '0';
			game->player_y++;
			game->map[game->player_y][game->player_x] = 'P';
		}
		else if (game->map[game->player_y + 1][game->player_x] == '0')
		{
			game->map[game->player_y][game->player_x] = '0';
			game->player_y++;
			game->map[game->player_y][game->player_x] = 'P';
		}
		else
			game->over = 1;
		game->moves++;
		mlx_clear_window(game->mlx, game->win);
	}
	draw_map(game);
}

void	move_d(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "xpm/player.xpm", &game->img_w, &game->img_h);
	if (game->map[game->player_y][game->player_x + 1] != '1' && (
		game->map[game->player_y][game->player_x + 1] != 'E' || !game->collect))
	{
		if (game->map[game->player_y][game->player_x + 1] == 'C')
		{
			game->collect--;
			game->map[game->player_y][game->player_x] = '0';
			game->player_x++;
			game->map[game->player_y][game->player_x] = 'P';
		}
		else if (game->map[game->player_y][game->player_x + 1] == '0')
		{
			game->map[game->player_y][game->player_x] = '0';
			game->player_x++;
			game->map[game->player_y][game->player_x] = 'P';
		}
		else
			game->over = 1;
		game->moves++;
		mlx_clear_window(game->mlx, game->win);
	}
	draw_map(game);
}
