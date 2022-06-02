/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:29:23 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/05/25 18:44:57 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_to_window(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 48, y * 48 + 20);
}

void	game_img(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "xpm/bot.xpm", &game->img_w, &game->img_h);
	game->img_mid = mlx_xpm_file_to_image
		(game->mlx, "xpm/mid.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "xpm/exit1.xpm", &game->img_w, &game->img_h);
	game->img_exit2 = mlx_xpm_file_to_image
		(game->mlx, "xpm/exit2.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "xpm/player.xpm", &game->img_w, &game->img_h);
	game->img_collect = mlx_xpm_file_to_image
		(game->mlx, "xpm/collect.xpm", &game->img_w, &game->img_h);
	game->img_foe = mlx_xpm_file_to_image
		(game->mlx, "xpm/foe.xpm", &game->img_w, &game->img_h);
}

void	game_win(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window
		(game->mlx, game->map_w * 48, game->map_h * 48 + 20, "so_long");
	game->moves = 0;
	game->over = 0;
	game->animation = 0;
	game->frame = 0;
	if (!check_foe_map(game))
		generate_foe(game);
	game_img(game);
	draw_map(game);
}
