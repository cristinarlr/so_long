/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:58:38 by crramire          #+#    #+#             */
/*   Updated: 2024/01/19 13:03:55 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void	free_map(char **map)
{
	int	i;

	ft_printf("🔥​free🔥​\n");
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	print_error_do_exit(char *error_message, t_game *game, int free_needed)
{
	ft_printf("🚫​ Error%s\n", error_message);
	ft_printf("​🔥🔥🔥🔥🔥🔥​​\n");
	if (free_needed == 1)
	{
		ft_printf("🔥free_map = case 1🔥\n");
		free_map(game->map.map);
	}
	if (free_needed == 2)
	{
		ft_printf("🔥free_map = case 2🔥\n");
		free_map(game->map.map);
	}
	exit(0);
}

/*CONSULTAR LO DE ESTE SEGUNDO FREE*/
/* if (free_needed == 2)
	{
		printf("🔥​free_map = case 2🔥​\n");
		//free_map(game->map.map_cpy);
		//Me da problemas de acceso a memoria
		//cuando quiero entrar en (game->map.map_cpy)
		free_map(game->map.map);
	} */
