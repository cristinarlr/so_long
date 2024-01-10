#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

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
    game.win = mlx_new_window(game.mlx, game.map.map_column_count * RESOLUTION_W, game.map.map_row_count * RESOLUTION_H, "So_Long!");
    ft_printf("2\n");
    print_graphics_in_win(game);
    ft_printf("3\n");
    mlx_key_hook(game.win, key_hook_control, &game);
    //mlx_hook(game.win, ON_DESTROY, 1L<<17, close_red_cross_window, &game);
    mlx_loop(game.mlx);
    //free(map);
    return(0);
}