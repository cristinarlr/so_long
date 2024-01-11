#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

/* PARA PRINTEAR Y TESTEAR */

void print_string(char *s)
{
    int i = 0;
    int count = 1;

    printf("Veamos la string:\n");
    while(s[i])
    {
        printf("s[%i] = %c; count: %i\n", i, s[i], count);
        i++;
        count++;
    }
    printf("s[%i] = NULL; count: %i\n", i, count);
}

void print_map(t_game *game)
{
    int i = 0;
    int j = 0;
    int count = 1;

ft_printf("Dentro de print_map:\n");
ft_printf("game->map.map_row_count = %i\n", game->map.map_row_count);
ft_printf("game->map.map_column_count = %i\n", game->map.map_column_count);
while(i < game->map.map_row_count)
    {
        while(j < game->map.map_column_count)
        {
            //printf("arr[%i][%i] = %c; count: %i\n", i, j, game->map.map[i][j], count);
            printf("%c", game->map.map[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
        count++;
    }
}

void print_data_structure(t_game *game)
{
    ft_printf("t_game:\n");
    ft_printf("game->map.map:\n");
    print_map(game);
    ft_printf("game->map.map_row_count:%i:\n", game->map.map_row_count);
    ft_printf("game->player_col:%i:\n", game->map.player_col);
    ft_printf("game->player_row:%i:\n", game->map.player_row);
    ft_printf("game->player_steps:%i:\n", game->map.player_steps);
    ft_printf("game->path_exit_count:%i:\n", game->map.path_exit_count);
    ft_printf("game->path_collectable_count:%i:\n", game->map.path_collectable_count);
    ft_printf("game->collectable_count:%i:\n", game->map.collectable_count);
}