/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:21:15 by crramire          #+#    #+#             */
/*   Updated: 2024/02/28 14:21:16 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void	init_data_map(t_map *map)
{
	map->map = NULL;
	map->map_cpy = NULL;
	map->map_row_count = 0;
	map->map_column_count = 0;
	map->flag_p = 0;
	map->flag_e = 0;
	map->flag_c = 0;
	map->player_col = 0;
	map->player_row = 0;
	map->player_steps = 0;
	map->path_exit_count = 0;
	map->path_collectable_count = 0;
	map->collectable_count = 0;
	map->player_front_img = NULL;
	map->player_back_img = NULL;
	map->player_left_img = NULL;
	map->player_right_img = NULL;
	map->wall_img = NULL;
	map->floor_img = NULL;
	map->collectable_img = NULL;
	map->exit_on_img = NULL;
	map->exit_off_img = NULL;
}
