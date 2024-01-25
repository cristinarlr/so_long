/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_testing_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:32:08 by crramire          #+#    #+#             */
/*   Updated: 2024/01/25 09:49:21 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void	init_ds_map(t_map *map)
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

void	print_ds_map(t_map *map)
{
	ft_printf("%p map->map\n", map->map);
	ft_printf("%p map->map_cpy\n", map->map_cpy);
	ft_printf("%p map->map_row_count\n", map->map_row_count);
	ft_printf("%p map->map_column_count\n", map->map_column_count);
	ft_printf("%p map->flag_e\n", map->flag_e);
	ft_printf("%p map->flag_p\n", map->flag_p);
	ft_printf("%p map->flag_c\n", map->flag_c);
	ft_printf("%p map->player_col\n", map->player_col);
	ft_printf("%p map->player_row\n", map->player_row);
	ft_printf("%p map->player_steps\n", map->player_steps);
	ft_printf("%p map->path_exit_count\n", map->path_exit_count);
	ft_printf("%p map->path_collectable_count\n", map->path_collectable_count);
	ft_printf("%p map->collectable_count\n", map->collectable_count);
	ft_printf("%p map->player_front_img\n", map->player_front_img);
	ft_printf("%p map->player_back_img\n", map->player_back_img);
	ft_printf("%p map->player_left_img\n", map->player_left_img);
	ft_printf("%p map->player_right_img\n", map->player_right_img);
	ft_printf("%p map->wall_img\n", map->wall_img);
	ft_printf("%p map->floor_img\n", map->floor_img);
	ft_printf("%p map->collectable_img\n", map->collectable_img);
	ft_printf("%p map->exit_on_img\n", map->exit_on_img);
	ft_printf("%p map->exit_off_img\n", map->exit_off_img);
}
