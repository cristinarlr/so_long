/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:03:36 by crramire          #+#    #+#             */
/*   Updated: 2024/01/22 10:47:12 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

static int	check_char(t_map *map, int i, int j)
{
	char	*abc;
	int		len;

	abc = "01PEC";
	len = strlen(map->map[i]);
	if (i == 0 || j == map->map_column_count)
	{
		if (map->map[i][j] != '1')
			return (ERROR);
	}
	else if (map->map[i][0] != '1' || map->map[i][len - 1] != '1')
		return (ERROR);
	else if ((ft_strchr(abc, map->map[i][j])) == 0)
		return (ERROR);
	return (NO_ERROR);
}

int	check_values(t_map *map)
{
	int		j;
	int		i;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (j < map->map_column_count)
		{
			if (check_char(map, i, j) == ERROR)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (NO_ERROR);
}

int	check_per(t_map *map, int i, int j)
{
	if (((map->map[i][j] == 'P') && map->flag_p == 1))
		return (ERROR);
	else if (((map->map[i][j] == 'E') && map->flag_e == 1))
		return (ERROR);
	if (map->map[i][j] == 'P')
	{
		map->player_row = i;
		map->player_col = j;
		map->flag_p = 1;
	}
	if (map->map[i][j] == 'E')
		map->flag_e = 1;
	if (map->map[i][j] == 'C')
	{
		map->collectable_count++;
		map->flag_c = 1;
	}
	return (NO_ERROR);
}

int	min_pec_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->collectable_count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (check_per(map, i, j) == ERROR)
				return (ERROR);
			j++;
		}
		i++;
	}
	if (map->flag_c == 1 && map->flag_e == 1 && map->flag_p == 1)
		return (NO_ERROR);
	else
		return (ERROR);
}
