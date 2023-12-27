#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

int main (int argc, char **argv)
{
    t_map *map;
    int i;
    
    map = NULL;
    i = argc;
    if (argc == 2)
    {
        map = malloc(sizeof(t_map));
        read_map(argv, map);
        free(map);
    }
    else
    {
        ft_printf("Error: Expecting a valid input, verify exe argument\n");
        return(-1);
    }
    return(0);
}