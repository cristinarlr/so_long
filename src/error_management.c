#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void free_map(char **map)
{
    int i;

    ft_printf("🔥​free🔥​\n");
    i = 0;
    while (map[i])
    {
        free(map[i]);
        //map[i] = NULL;
        i++;
    }
    free(map);
}

int print_error_do_exit(char *error_message, t_game *game, int free_needed)
{
    ft_printf("🚫​ Error%s\n", error_message);
    ft_printf("​🔥🔥🔥🔥🔥🔥​​\n");
    ft_printf("​POINTER MAP.CPY = %p​​\n", game->map.map_cpy);
    ft_printf("​POINTER MAP = %p​​\n", game->map.map);
    if(free_needed == 1)
    {
        printf("free_map = case 1\n");
        free_map(game->map.map);
    }
    if(free_needed == 2)
    {
        printf("🔥​free_map = case 2🔥​\n");
        //free_map(game->map.map_cpy);
        //Me da problemas de acceso a memoria cuando quiero entrar en (game->map.map_cpy)
        free_map(game->map.map);
    }
    exit(0);
}


/*     ft_printf("​🎈​​MAP. MAP🎈​​\n");
    print_map(game);
    ft_printf("​🎈​​MAP. MAP.MAP_CPY🎈​​\n");
    print_map_cpy(game); */