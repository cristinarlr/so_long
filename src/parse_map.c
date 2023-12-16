#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

//values OK

//first or last str filled of 1s
void parse_map (t_map *map)
{
    int i;
    int j;
    char *abc;
    int flag;

    printf("\ndentro de parse_map\n");
    i = 0;
    flag = 0;
    abc = "01PEC";
    while (map->map[i])
    {
        //pasar valores a mayúsculas (es necesario gestionar eso?)
        printf("While 1\n");
        j = 0;
        while ( j <= map->map_column_count)
        {
            //primera o última fila rellena de 1s
            printf("While 2\n");
            if (i == 0 || i == map->map_row_count)
            {
                if (map->map[i][j] != '1')
                {
                    printf("Error 1st o last row\n");
                    printf("%s\n", strerror(errno));
                }
            }
            //primer o último valor de la fila relleno de 1s
            else if (map->map[i][0] != '1' || map->map[i][strlen(map->map[i])] != '1')
            {
                    printf("Error 1st o last position middle rows\n");
                    printf("map[%i] = %s, map[%i][%i] = %c\n", i, map->map[i], i, j, map->map[i][j]);
                    exit(-1);
            }
            //valores intermedios corresponden a "01PEC"
            else if (ft_strchr(abc, map->map[i][j]) == NULL)
            {
                printf("Error character not valid\n");
                exit(-1);
            }
            j++;
        }
        i++;
    }
    printf("^^^^^^^^^ PARSE OK!! ^^^^^^^^^\n");
}







//way to exit OK