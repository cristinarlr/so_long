#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

//ARREGLAR MAP ROW COUNT

static int check_values(t_map *map)
{
    int i;
    int j;
    int len;
    char *abc;
   
    printf("dentro de check_values\n");
    i = 0;
    len = strlen(map->map[i]);
    printf("len = %i\n", len);
    abc = "01PEC";
    printf("map->map_column_count = %i\n", map->map_column_count);
    
    while (map->map[i])
    {
        j = 0;
        while (j < map->map_column_count)
        {
            //first or last str filled of 1s
                printf("While 2; i = %i; str = %s; char = %c\n", i, map->map[i], map->map[i][j]);
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
                //primer o último valor de la fila relleno de 1s
                //ASI PETABA HEAP OVERFLOW Y NO SE PQ:
                //else if (s[0] != '1' || s[strlen(map->map[i]) - 1] != '1')
                else if (map->map[i][0] != '1' || map->map[i][len - 1] != '1')
                {
                        printf("check_values - Error 1st o last position middle rows has to be 1\n");
                        printf("s = %s, c = %c\n", map->map[i], map->map[i][j]);
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

    i = 0;
    printf("dentro de min_pec_char\n");
    flag_p = 0;
    flag_e = 0;
    flag_c = 0;
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
                flag_p = 1;
            if (map->map[i][j] == 'E')
                flag_e = 1;
            if (map->map[i][j] == 'C')
                flag_c = 1;
            j++;
        }
        i++;
    }
    if (flag_c == 1 && flag_e == 1 && flag_p == 1)
        return (NO_ERROR);
    else 
    {
        //printf("*** ERROR in PEC ***\n");
        //printf ("flag_p = %i; flag_e = %i; flag_c = %i;\n", flag_p, flag_e, flag_c);
        return (ERROR);
    }
}

/* static int  valid_way_to_exit(t_map *map)
{


    return(NO_ERROR);
} */

void parse_map (t_map *map)
{
    int i;

    printf("dentro de parse_map\n");
    i = 0;
    if (check_values(map) == ERROR)
    {
        printf("check_values = ERROR\n");
        exit(-1);
    }
    if (min_pec_char(map) == ERROR)
    {
        printf("check_PEC_char= ERROR\n");
        exit(-1);
    }
    /* if (valid_way_to_exit(map) == ERROR)
    {
        printf("valid_way= ERROR\n");
        exit(-1);
    } */
    i++;
    printf("^^^^^^^^^ PARSE OK!! ^^^^^^^^^\n");
}