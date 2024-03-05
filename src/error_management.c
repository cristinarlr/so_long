/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:58:38 by crramire          #+#    #+#             */
/*   Updated: 2024/02/28 14:50:45 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	print_error_do_exit(char *error_message, t_game *game)
{
	if (error_message != NULL)
		ft_printf("Error%s", error_message);
	if (game->map.map_cpy)
		free_map(game->map.map_cpy);
	if (game->map.map)
		free_map(game->map.map);
	exit(0);
}
