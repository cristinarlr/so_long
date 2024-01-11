#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

static int check_values(t_map *map)
{
    int i;
    int j;
    int len;
    char *abc;
   
    printf("dentro de check_values\n");
    i = 0;
    len = strlen(map->map[i]);
    abc = "01PEC";
    while (map->map[i])
    {
        j = 0;
        while (j < map->map_column_count)
        {
            //first or last str filled of 1s
            //printf("While 2; i = %i; str = %s; char = %c\n", i, map->map[i], map->map[i][j]);
            if (j == 0 || j == map->map_column_count)
            {
                if (map->map[i][j] != '1')
                {
                    printf("check_values - Error 1st o last row\n");
                    printf("map->map[%i][%i] = %c\n", i, j, map->map[i][j]);
                    printf("%s\n", strerror(errno));
                    return(ERROR);
                }
            }
            //primer o último valor de las filas relleno de 1s
            //ASI PETABA HEAP OVERFLOW Y NO SE PQ:
            //else if (s[0] != '1' || s[strlen(map->map[i]) - 1] != '1')
            else if (map->map[i][0] != '1' || map->map[i][len - 1] != '1')
            {
                    printf("check_values - Error 1st o last position middle rows has to be 1\n");
                    //printf("s = %s, c = %c\n", map->map[i], map->map[i][j]);
                    return(ERROR);
            } 
            //valores intermedios corresponden a "01PEC"
            else if ((ft_strchr(abc, map->map[i][j])) == 0)
            {
                printf("check_values - Error character not valid\n");
                return(ERROR);
            }
            j++;
        }
        i++;
    }
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
    printf("dentro de min_pec_char\n");
    flag_p = 0;
    flag_e = 0;
    flag_c = 0;
    map->collectable_count = 0;
    while(map->map[i])
    {
        j = 0;
        while(map->map[i][j])
        {
            //printf("WHILE 2 - min_pec_char, map[%i][%i] = %c\n", i , j, map->map[i][j]);
            if (((map->map[i][j] == 'P') && flag_p == 1))
                return (ERROR);
            else if (((map->map[i][j] == 'E') && flag_e == 1))
                return (ERROR);
            if (map->map[i][j] == 'P')
            {
                map->player_row = i;
                map->player_col = j;
                //printf("map->player_row = %i; map->player_col = %i\n", map->player_row, map->player_col);
                flag_p = 1;
            }
            if (map->map[i][j] == 'E')
                flag_e = 1;
            if (map->map[i][j] == 'C')
            {
                map->collectable_count++;
                //printf("map->collectable_count = %i\n", map->collectable_count);
                flag_c = 1;
            }
            j++;
        }
        i++;
    }
    if (flag_c == 1 && flag_e == 1 && flag_p == 1)
        return (NO_ERROR);
    else 
    {
        printf("*** ERROR in PEC ***\n");
        //printf ("flag_p = %i; flag_e = %i; flag_c = %i;\n", flag_p, flag_e, flag_c);
        return (ERROR);
    }
}

void    check_flood_fill_path(t_map *map, int row, int col)
{
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
    printf("dentro de check_valid_path\n");
    map->path_exit_count = 0;
    map->path_collectable_count = 0;
    check_flood_fill_path(map, map->player_row, map->player_col);
    //printf("map->collectable_count = %i; map->path_collectable_count = %i; map->path_exit_count = %i\n", map->collectable_count, map->path_collectable_count, map->path_exit_count);
    if(map->collectable_count == map->path_collectable_count && map->path_exit_count)
        return(NO_ERROR);
    else
        return(ERROR);
}

void parse_map (t_map *map)
{
    int i;

    printf("\ndentro de parse_map\n");
    i = 0;
    if (check_values(map) == ERROR)
    {
        printf("check_values = ERROR\n");
        exit(-1);
    }
    if (min_pec_char(map) == ERROR)
    {
        printf("check_PEC_char = ERROR\n");
        exit(-1);
    }
    if (check_valid_path(map) == ERROR)
    {
        printf("valid_way = ERROR\n");
        exit(-1);
    }
    i++;
    printf("^^^^^^^^^ PARSE OK!! ^^^^^^^^^\n");
}