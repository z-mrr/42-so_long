/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:24:08 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/05/25 17:53:01 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_file(char *file)
{
	int	i;

	i = 0;
	while (file[i + 1])
		i++;
	if (file[i] == 'r' && file[i - 1] == 'e'
		&& file[i - 2] == 'b' && file[i - 3] == '.'
		&& file[i - 4])
		return (1);
	else
		return (0);
}

void	error_msg(t_game *game)
{
	if (game->map)
		free_map(game->map);
	ft_printf("Error\nInvalid map.\n");
	exit (-1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2 && check_file(av[1]))
	{
		game.map = read_map(av[1]);
		if (check_map(&game))
		{
			game_win(&game);
			mlx_hook(game.win, 17, 0, exit_game, &game);
			mlx_key_hook(game.win, read_keys, &game);
			mlx_hook(game.win, 02, (1L << 0), continuous_read_keys, &game);
			mlx_loop_hook(game.mlx, animation, &game);
			mlx_loop(game.mlx);
		}
		else
			error_msg(&game);
	}
	else
	{
		ft_printf("Error\nInvalid path to a .ber file.\n");
		exit (-1);
	}
	return (0);
}
