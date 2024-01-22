/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:36:21 by crramire          #+#    #+#             */
/*   Updated: 2024/01/22 12:54:13 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../inc/so_long.h"

static int	map_rows(char **argv, int fd)
{
	int		i;
	char	*line;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		i++;
	}
	return (i);
}

static void	load_map(t_map *map, int fd)
{
	int	i;
	int	raw;

	i = 0;
	raw = map->map_row_count;
	while (raw > 0)
	{
		map->map[i] = ft_strtrim(get_next_line(fd), "\n");
		i++;
		raw--;
	}
	map->map[i] = NULL;
}

static void	is_it_squared(t_map *map, t_game *game)
{
	int	i;
	int	len;
	int	cmp_len;

	i = 0;
	if (map->map[i] != 0)
		len = ft_strlen(map->map[i]);
	while (map->map[i] != NULL)
	{
		cmp_len = ft_strlen(map->map[i]);
		if (len != cmp_len)
			print_error_do_exit(ERRORMSG_5, game, 1);
		i++;
	}
	map->map_column_count = len;
}

static void	copy_map(t_map *map, t_game *game)
{
	int	i;

	i = 0;
	map->map_cpy = malloc(sizeof(char **) * (map->map_row_count + 1));
	if (!map->map_cpy)
		print_error_do_exit(ERRORMSG_6, game, 2);
	while (i < (map->map_row_count))
	{
		map->map_cpy[i] = ft_strdup(map->map[i]);
		i++;
	}
	map->map_cpy[i] = NULL;
}

int	read_map(char **argv, t_map *map, t_game *game)
{
	int	fd;
	int	raws;

	init_ds_map(map);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (print_error_do_exit(ERRORMSG_3, game, 0));
	raws = map_rows(argv, fd);
	map->map = malloc(sizeof(char **) * (raws + 1));
	if (!map->map)
		return (print_error_do_exit(ERRORMSG_4, game, 1));
	map->map_row_count = raws;
	load_map(map, fd);
	close(fd);
	is_it_squared(map, game);
	if (map->map_column_count > 75 || map->map_row_count > 40)
		return (print_error_do_exit(ERRORMSG_5_1, game, 1));
	copy_map(map, game);
	parse_map(map, game);
	return (0);
}
