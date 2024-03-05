/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:05:10 by crramire          #+#    #+#             */
/*   Updated: 2024/02/28 13:05:42 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void	load_xpm_background(t_game *game)
{
	int	width;
	int	height;

	game->map.wall_img
		= mlx_xpm_file_to_image(game->mlx, XPM_6, &width, &height);
	game->map.floor_img
		= mlx_xpm_file_to_image(game->mlx, XPM_7, &width, &height);
	game->map.exit_on_img
		= mlx_xpm_file_to_image(game->mlx, XPM_8, &width, &height);
	game->map.exit_off_img
		= mlx_xpm_file_to_image(game->mlx, XPM_9, &width, &height);
	if (!game->map.wall_img || !game->map.floor_img
		|| !game->map.exit_on_img || !game->map.exit_off_img)
		print_error_do_exit(ERRORMSG_10, game);
}

void	load_xpm_to_data_structure(t_game *game)
{
	int	width;
	int	height;

	load_xpm_background(game);
	game->map.collectable_img
		= mlx_xpm_file_to_image(game->mlx, XPM_1, &width, &height);
	game->map.player_front_img
		= mlx_xpm_file_to_image(game->mlx, XPM_2, &width, &height);
	game->map.player_back_img
		= mlx_xpm_file_to_image(game->mlx, XPM_3, &width, &height);
	game->map.player_left_img
		= mlx_xpm_file_to_image(game->mlx, XPM_4, &width, &height);
	game->map.player_right_img
		= mlx_xpm_file_to_image(game->mlx, XPM_5, &width, &height);
	if (!game->map.collectable_img || !game->map.player_front_img
		|| !game->map.player_back_img || !game->map.player_left_img
		|| !game->map.player_right_img)
		print_error_do_exit(ERRORMSG_10, game);
}

void	select_square_grid_image(t_game *game, int row, int col)
{
	if (game->map.map[row][col] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.wall_img, col * RESOLUTION_W, row * RESOLUTION_H);
	else if (game->map.map[row][col] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.floor_img, col * RESOLUTION_W, row * RESOLUTION_H);
	else if (game->map.map[row][col] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.player_front_img, col * RESOLUTION_W, row * RESOLUTION_H);
	else if (game->map.map[row][col] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.exit_off_img, col * RESOLUTION_W, row * RESOLUTION_H);
		if (game->map.collectable_count == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->map.exit_on_img, col * RESOLUTION_W, row * RESOLUTION_H);
	}
	else if (game->map.map[row][col] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.collectable_img, col * RESOLUTION_W, row * RESOLUTION_H);
}

void	print_xpm_on_map(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map.map_row_count)
	{
		col = 0;
		while (col < game->map.map_column_count)
		{
			select_square_grid_image(game, row, col);
			col++;
		}
		row++;
	}
	return ;
}

void	print_graphics_in_win(t_game game)
{
	load_xpm_to_data_structure(&game);
	print_xpm_on_map(&game);
}
