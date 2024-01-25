/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_testing_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:32:08 by crramire          #+#    #+#             */
/*   Updated: 2024/01/25 09:49:29 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void	print_string(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i])
	{
		ft_printf("s[%i] = %c; count: %i\n", i, s[i], count);
		i++;
		count++;
	}
	ft_printf("s[%i] = NULL; count: %i\n", i, count);
}

void	print_map(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 1;
	while (i < game->map.map_row_count)
	{
		while (j < game->map.map_column_count)
		{
			ft_printf("%c", game->map.map[i][j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
		count++;
	}
}

void	print_map_cpy(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 1;
	while (i < game->map.map_row_count)
	{
		while (j < game->map.map_column_count)
		{
			printf("%c", game->map.map_cpy[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
		count++;
	}
}

void	print_data_structure(t_game *game)
{
	ft_printf("t_game:\n");
	ft_printf("game->map.map:\n");
	print_map(game);
	ft_printf("game->map.map_row_count:%i:\n", game->map.map_row_count);
	ft_printf("game->player_col:%i:\n", game->map.player_col);
	ft_printf("game->player_row:%i:\n", game->map.player_row);
	ft_printf("game->player_steps:%i:\n", game->map.player_steps);
	ft_printf("game->path_exit_count:%i:\n", game->map.path_exit_count);
	ft_printf("game->path_collectable_count:%i:\n",
		game->map.path_collectable_count);
	ft_printf("game->collectable_count:%i:\n", game->map.collectable_count);
}
