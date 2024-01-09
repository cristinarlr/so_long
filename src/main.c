#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

int	close_red_cross_window(t_game *game)
{
	printf("close window\n");
	mlx_destroy_window(game->mlx, game->win);
	exit(NO_ERROR);
}

int key_hook(int keycode, t_game *game)
{
    printf("key hook - keycode: %d\n", keycode);
	if(keycode == 53)
		close_red_cross_window(game);
	if(keycode == 0)
		printf("A is pressed!\n");
	return(0);
}

int check_valid_map_format(char *argv)
{
    int len;

    //falta añadir control de errores (mensaje si error)
    len = ft_strlen(argv);
    if(argv[len - 4] == '.' && argv[len -3] == 'b' && argv[len -2] == 'e' && argv[len - 1] == 'r')
        return(NO_ERROR);
    else
        return(ERROR);
}

int main (int argc, char **argv)
{
    //t_map   *map;
    int i;
    t_game  game;
    
    //map = NULL;
    ft_bzero(&game, 0);
    i = argc;
    if (argc == 2)
    {
        //map = malloc(sizeof(t_map));
        if(check_valid_map_format(argv[1]) == NO_ERROR)
            //read_map(argv, map);
            read_map(argv, &game.map);
        //free(map);
    }
    else
    {
        ft_printf("Error: Expecting a valid input, verify exe argument\n");
        return(-1);
    }
    ft_printf("GAME STARTS ... \n");
    game.mlx = mlx_init();
    ft_printf("1\n");
    game.win = mlx_new_window(game.mlx, game.map.map_column_count * 50, game.map.map_row_count * 50, "So_Long!");
    ft_printf("2\n");
    print_graphics_in_win(game);
    ft_printf("3\n");
    mlx_key_hook(game.win, key_hook, &game);
    mlx_hook(game.win, ON_DESTROY, 1L<<17, close_red_cross_window, &game);
    mlx_loop(game.mlx);
    
    /* map->mlx = mlx_init();
    map->win = mlx_new_window(map->mlx, map->map_column_count * 50, map->map_row_count * 50, "So_Long!");
    print_graphics_in_win(map);
    mlx_key_hook(map->win, key_hook, &map);
    mlx_hook(map->win, ON_DESTROY, 1L<<17, close_red_cross_window, map); //Window close event with x red button
    mlx_loop(map->mlx); */
    //free(map);
    return(0);
}