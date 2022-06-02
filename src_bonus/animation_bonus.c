/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:46:46 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/06/02 10:44:38 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_text(t_game game)
{
	char	*str;

	str = ft_itoa(game.moves);
	mlx_string_put(game.mlx, game.win,
		game.map_w * 48 / 2 - 40, 0, 0xFFFFFF, "MOVES: ");
	mlx_string_put(game.mlx, game.win,
		game.map_w * 48 / 2 + 26, 0, 0xFFFFFF, str);
	free(str);
}

int	animation(t_game *game)
{
	game->frame++;
	if (!(game->frame % 1000) && game->collect)
	{
		game->animation++;
		mlx_destroy_image(game->mlx, game->img_collect);
		collect_animation(game);
		draw_map(game);
	}
	return (0);
}

void	collect_animation(t_game *game)
{
	if (game->animation == 0)
		game->img_collect = mlx_xpm_file_to_image
			(game->mlx, "xpm/collect1.xpm", &game->img_w, &game->img_h);
	else if (game->animation == 1)
		game->img_collect = mlx_xpm_file_to_image
			(game->mlx, "xpm/collect2.xpm", &game->img_w, &game->img_h);
	else if (game->animation == 2)
		game->img_collect = mlx_xpm_file_to_image
			(game->mlx, "xpm/collect3.xpm", &game->img_w, &game->img_h);
	else if (game->animation == 3)
		game->img_collect = mlx_xpm_file_to_image
			(game->mlx, "xpm/collect4.xpm", &game->img_w, &game->img_h);
	else if (game->animation == 4)
		game->img_collect = mlx_xpm_file_to_image
			(game->mlx, "xpm/collect5.xpm", &game->img_w, &game->img_h);
	else if (game->animation == 5)
	{
		game->img_collect = mlx_xpm_file_to_image
			(game->mlx, "xpm/collect.xpm", &game->img_w, &game->img_h);
		game->animation = 0;
	}
}
