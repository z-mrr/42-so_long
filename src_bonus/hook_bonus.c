/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:10:14 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/06/02 10:40:31 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free (map);
	map = 0;
}

int	exit_game(t_game *game)
{
	free_map (game->map);
	mlx_destroy_image (game->mlx, game->img_mid);
	mlx_destroy_image (game->mlx, game->img_wall);
	mlx_destroy_image (game->mlx, game->img_player);
	mlx_destroy_image (game->mlx, game->img_collect);
	mlx_destroy_image (game->mlx, game->img_exit);
	mlx_destroy_image (game->mlx, game->img_exit2);
	mlx_destroy_image (game->mlx, game->img_foe);
	mlx_destroy_window (game->mlx, game->win);
	free (game->mlx);
	exit (0);
}

int	read_keys(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		exit_game(game);
	return (0);
}

int	continuous_read_keys(int keycode, t_game *game)
{
	if (game->over)
		return (0);
	else if (keycode == K_W)
		move_w(game);
	else if (keycode == K_A)
		move_a(game);
	else if (keycode == K_S)
		move_s(game);
	else if (keycode == K_D)
		move_d(game);
	return (0);
}
