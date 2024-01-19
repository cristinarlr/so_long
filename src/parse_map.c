#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

static int check_values(t_map *map)
{
    int i;
    int j;
    int len;
    char *abc;
   
    i = 0;
    len = strlen(map->map[i]);
    abc = "01PEC";
    ft_printf("Dentro de check_values\n");
    while (map->map[i])
    {
        j = 0;
        while (j < map->map_column_count)
        {
            if (i == 0 || i == map->map_column_count)
            {
                if (map->map[i][j] != '1')
                {
                    return(ERROR);
                }
            }
            else if (map->map[i][0] != '1' || map->map[i][len - 1] != '1')
            {
                return(ERROR);
            }
            else if ((ft_strchr(abc, map->map[i][j])) == 0)
            {
                return(ERROR);
            }
            j++;
        }
        i++;
    }
    ft_printf("Fuera de check_values\n");
    return(NO_ERROR);
}

static int min_pec_char(t_map *map)
{
    int flag_p;
    int flag_e;
    int flag_c;
    int i;
    int j;

//si me paso de líneas de norminette meter los flags en la estructura de map en header y me ahorro líneas
    i = 0;
    flag_p = 0;
    flag_e = 0;
    flag_c = 0;
    map->collectable_count = 0;
    while(map->map[i])
    {
        j = 0;
        while(map->map[i][j])
        {
            if (((map->map[i][j] == 'P') && flag_p == 1))
                return (ERROR);
            else if (((map->map[i][j] == 'E') && flag_e == 1))
                return (ERROR);
            if (map->map[i][j] == 'P')
            {
                map->player_row = i;
                map->player_col = j;
                flag_p = 1;
            }
            if (map->map[i][j] == 'E')
                flag_e = 1;
            if (map->map[i][j] == 'C')
            {
                map->collectable_count++;
                flag_c = 1;
            }
            j++;
        }
        i++;
    }
    if (flag_c == 1 && flag_e == 1 && flag_p == 1)
        return (NO_ERROR);
    else 
        return (ERROR);
}

void    check_flood_fill_path(t_map *map, int row, int col)
{
    //printf("BEFORE adress map->map_cpy = %p\nmap->map_cpy[%i][%i] = %c", map->map_cpy, row, col, map->map_cpy[row][col]);
    if(map->map_cpy[row][col] == 'E')
        map->path_exit_count++;
    if(map->map_cpy[row][col] == 'C')
        map->path_collectable_count++;
    if(row < 0 || row > map->map_row_count 
        || col < 0 || col > map ->map_column_count 
        || map->map_cpy[row][col] == '1' 
        || map->map_cpy[row][col] == 'E'
        || map->map_cpy[row][col] == 'F')
        return ;
    map->map_cpy[row][col] = 'F';
    check_flood_fill_path(map, row + 1, col);
    check_flood_fill_path(map, row - 1, col);
    check_flood_fill_path(map, row, col + 1);
    check_flood_fill_path(map, row, col - 1);
    return ;
}

static int  check_valid_path(t_map *map)
{
    map->path_exit_count = 0;
    map->path_collectable_count = 0;
    check_flood_fill_path(map, map->player_row, map->player_col);
    if(map->collectable_count == map->path_collectable_count && map->path_exit_count)
        return(NO_ERROR);
    else
        return(ERROR);
}

void parse_map (t_map *map, t_game *game)
{
    int i;

    i = 0;
    if (check_values(map) == ERROR)
    {
        print_error_do_exit(": Invalid map values.\n   >> Only 1, 0, P, E and C are allowed.\n   >> Map frame has to be built with 1 values.\n", game, 2);
    }
    if (min_pec_char(map) == ERROR)
        print_error_do_exit(": Invalid map values. Only one player (P), one exit (E) allowed and at least one collectable (C).\n", game, 2);
    if (check_valid_path(map) == ERROR)
        print_error_do_exit(": Invalid path. Impossible to collect everything or access to exit.\n", game, 2);
    i++;
}