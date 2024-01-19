/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:06:01 by Cristina          #+#    #+#             */
/*   Updated: 2024/01/19 10:35:01 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

int	check_valid_map_format(char *argv, t_game *game)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[len - 4] == '.' && argv[len -3] == 'b'
		&& argv[len -2] == 'e' && argv[len - 1] == 'r')
		return (NO_ERROR);
	else
		return (print_error_do_exit (ERRORMSG_1, game, 0));
}

void	leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	int		i;
	t_game	game;

	ft_bzero(&game, 0);
	i = argc;
	if (argc == 2)
	{
		if (check_valid_map_format(argv[1], &game) == NO_ERROR)
			read_map(argv, &game.map, &game);
	}
	else
		return (print_error_do_exit(ERRORMSG_2, &game, 0));
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
			game.map.map_column_count * RESOLUTION_W,
			game.map.map_row_count * RESOLUTION_H, "SO_LONG!");
	print_graphics_in_win(game);
	mlx_key_hook(game.win, key_hook_control, &game);
	mlx_hook(game.win, ON_DESTROY, 1L << 17, close_red_cross_window, &game);
	mlx_loop(game.mlx);
	free_map(game.map.map);
	system("leaks so_long");
	return (0);
}
