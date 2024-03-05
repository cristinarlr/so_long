/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:03:36 by crramire          #+#    #+#             */
/*   Updated: 2024/02/28 13:05:59 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void	check_flood_fill_path(t_map *map, int row, int col)
{
	if (map->map_cpy[row][col] == 'E')
		map->path_exit_count++;
	if (map->map_cpy[row][col] == 'C')
		map->path_collectable_count++;
	if (row < 0 || row > map->map_row_count
		|| col < 0 || col > map ->map_column_count
		|| map->map_cpy[row][col] == '1'
		|| map->map_cpy[row][col] == 'E'
		|| map->map_cpy[row][col] == 'F')
		return ;
	map->map_cpy[row][col] = 'F';
	check_flood_fill_path(map, row + 1, col);
	check_flood_fill_path(map, row - 1, col);
	check_flood_fill_path(map, row, col + 1);
	check_flood_fill_path(map, row, col - 1);
	return ;
}

static int	check_valid_path(t_map *map)
{
	map->path_exit_count = 0;
	map->path_collectable_count = 0;
	check_flood_fill_path(map, map->player_row, map->player_col);
	if (map->collectable_count == map->path_collectable_count
		&& map->path_exit_count)
		return (NO_ERROR);
	else
		return (ERROR);
}

void	parse_map(t_map *map, t_game *game)
{
	int	i;

	i = 0;
	if (check_values(map) == ERROR)
		print_error_do_exit(ERRORMSG_7, game);
	if (min_pec_char(map) == ERROR)
		print_error_do_exit(ERRORMSG_8, game);
	if (check_valid_path(map) == ERROR)
		print_error_do_exit(ERRORMSG_9, game);
	i++;
}
