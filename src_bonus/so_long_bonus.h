/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:16:25 by jdias-mo          #+#    #+#             */
/*   Updated: 2022/06/02 10:44:41 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

//# include "../minilibx-linux/mlx.h"
# include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>

# define K_ESC 53
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_mid;
	void	*img_wall;
	void	*img_exit;
	void	*img_exit2;
	void	*img_player;
	void	*img_collect;
	void	*img_foe;
	char	**map;
	int		img_h;
	int		img_w;
	int		map_h;
	int		map_w;
	int		player_x;
	int		player_y;
	int		exit;
	int		player;
	int		collect;
	int		moves;
	int		over;
	int		animation;
	int		frame;
}	t_game;

void	error_msg(t_game *game);
int		check_file(char *file);

char	**read_map(char *file);
int		check_map(t_game *game);
int		check_map_components(t_game *game);
int		check_map_walls(t_game game);
int		check_map_size(t_game *game);

void	game_win(t_game *game);
void	game_img(t_game *game);
void	img_to_window(t_game *game, void *image, int x, int y);

int		draw_map(t_game *game);
void	draw_exit(t_game *game, int x, int y);
void	draw_player(t_game *game, int x, int y);

void	free_map(char **map);
int		exit_game(t_game *game);
int		read_keys(int keycode, t_game *game);
int		continuous_read_keys(int keycode, t_game *game);

void	draw_text(t_game game);
void	collect_animation(t_game *game);
int		animation(t_game *game);

int		check_foe_map(t_game *game);
void	generate_foe(t_game *game);
int		check_foe(char **map, int i, int j);

void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);

#endif
