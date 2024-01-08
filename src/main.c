#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

int	close_window(t_map *map)
{
	printf("close window\n");
	mlx_destroy_window(map->mlx, map->win);
	exit(NO_ERROR);
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
    t_map *map;
    //t_game  game;
    int i;
    
    map = NULL;
    i = argc;
    if (argc == 2)
    {
        map = malloc(sizeof(t_map));
        if(check_valid_map_format(argv[1]) == NO_ERROR)
            read_map(argv, map);
        //free(map);
    }
    else
    {
        ft_printf("Error: Expecting a valid input, verify exe argument\n");
        return(-1);
    }
    //ft_memset(&game, 0, sizeof(game));
    //game.mlx = mlx_init();
    //game.win = mlx_new_window(game.mlx, 800, 600, "MOVING RAINBOW!");
    //printf("game.map.map_column_count = %i\n", game.map.map_column_count);
    //game.win = mlx_new_window(game.mlx, (game.map.map_column_count * 128), (game.map.map_row_count * 128), "so_long");
    //ft_print_graphics_in_win() -- CREAR FUNCIÓN
    //mlx_loop(game.mlx);
    //free(&game);
    map->mlx = mlx_init();
    map->win = mlx_new_window(map->mlx, map->map_column_count * 50, map->map_row_count * 50, "So_Long!");
    mlx_hook(map->win, 2, 1L<<0, close, map); //key press event
    mlx_hook(map->win, ON_DESTROY, 1L<<17, close_window, map); //Window close event with x red button
    mlx_loop(map->mlx);
    free(map);

    return(0);
}