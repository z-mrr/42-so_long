/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:41:37 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/06/02 11:04:35 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_size(t_game *game)
{
	int	h;
	int	w;
	int	last_w;

	h = 0;
	w = 0;
	last_w = 0;
	while (game->map[h])
	{
		w = 0;
		while (game->map[h][w])
			w++;
		if (h && last_w != w)
			return (0);
		last_w = w;
		h++;
	}
	if (h < 3 || (h && h == w))
		return (0);
	game->map_h = h;
	game->map_w = w;
	return (1);
}

int	check_map_walls(t_game game)
{
	int	i;

	i = 0;
	while (i < game.map_w)
	{
		if (game.map[0][i] != '1' || game.map[game.map_h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game.map_h)
	{
		if (game.map[i][0] != '1' || game.map[i][game.map_w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_components(t_game *game)
{
	int	i;
	int	j;

	game->exit = 0;
	game->collect = 0;
	game->player = 0;
	i = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->collect++;
			else if (game->map[i][j] == 'P')
				game->player++;
			j++;
		}
		i++;
	}
	if (!game->exit || !game->collect || game->player != 1)
		return (0);
	return (1);
}

int	check_map(t_game *game)
{
	int	i;
	int	j;

	if (!game->map)
		return (0);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != 'E' && game->map[i][j] != 'C'
			&& game->map[i][j] != 'P' && game->map[i][j] != '1'
			&& game->map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	if (check_map_size(game) && check_map_walls(*game)
		&& check_map_components(game))
		return (1);
	return (0);
}

char	**read_map(char *file)
{
	char	**map;
	char	*line;
	char	*temp_map;
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	temp_map = malloc(sizeof(char));
	temp_map[0] = '\0';
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = temp_map;
		temp_map = ft_strjoin(temp_map, line);
		free (line);
		free (temp);
	}
	map = ft_split(temp_map, '\n');
	free (temp_map);
	close (fd);
	return (map);
}
