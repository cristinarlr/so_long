/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:16:33 by crramire          #+#    #+#             */
/*   Updated: 2024/02/28 14:20:38 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

int	close_red_cross_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(NO_ERROR);
}

static void	add_mvmnt(int new_row, int new_col, t_game *game)
{
	game->map.player_row = new_row;
	game->map.player_col = new_col;
	game->map.player_steps++;
}

static int	valid_mvmnt(int new_row, int new_col, t_game *game)
{
	if (game->map.map[new_row][new_col] == '0')
	{
		game->map.map[new_row][new_col] = 'P';
		add_mvmnt(new_row, new_col, game);
	}
	if (game->map.map[new_row][new_col] == 'C')
	{
		game->map.map[new_row][new_col] = 'P';
		add_mvmnt(new_row, new_col, game);
		game->map.collectable_count--;
	}
	if (game->map.map[new_row][new_col] == 'E')
	{
		if (game->map.collectable_count != 0)
			return (1);
		game->map.player_steps++;
		ft_printf("%s", SUCCESSMSG);
		print_error_do_exit(NULL, game);
	}
	if (game->map.map[new_row][new_col] == '1')
		return (1);
	return (NO_ERROR);
}

static int	do_move(int keycode, t_game *game)
{
	int	current_row;
	int	current_col;
	int	scroll_row;
	int	scroll_col;

	current_row = game->map.player_row;
	current_col = game->map.player_col;
	scroll_row = 0;
	scroll_col = 0;
	if (keycode == LEFT || keycode == A_LEFT)
		scroll_col = -1;
	if (keycode == RIGHT || keycode == D_RIGHT)
		scroll_col = 1;
	if (keycode == UP || keycode == W_UP)
		scroll_row = -1;
	if (keycode == DOWN || keycode == S_DOWN)
		scroll_row = 1;
	if (valid_mvmnt(scroll_row + current_row,
			scroll_col + current_col, game) == 1)
		return (0);
	if (valid_mvmnt(scroll_row + current_row,
			scroll_col + current_col, game) == ERROR)
		return (ERROR);
	game->map.map[current_row][current_col] = '0';
	return (NO_ERROR);
}

int	key_hook_control(int keycode, t_game *game)
{
	int	feasible_move;

	feasible_move = 0;
	if (keycode == ESC || keycode == Q_QUIT)
		close_red_cross_window(game);
	if (keycode == LEFT || keycode == A_LEFT
		|| keycode == RIGHT || keycode == D_RIGHT
		|| keycode == UP || keycode == W_UP
		|| keycode == DOWN || keycode == S_DOWN)
	{
		feasible_move = do_move(keycode, game);
		ft_printf("steps: %i\n", game->map.player_steps);
	}
	if (feasible_move == 0)
		print_graphics_in_win(*game);
	return (0);
}
