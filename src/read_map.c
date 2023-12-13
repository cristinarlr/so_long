#include "../inc/get_next_line.h"
#include "../inc/so_long.h"

int read_map(char **argv, t_map *map)
{
    int fd;
   
    printf("dentro de read_map\n");
    map->map_raw_count = 0;
    printf("1\n");
    fd = open(argv[map->map_raw_count], O_RDONLY);
    while((map->map[map->map_raw_count]= get_next_line(fd)) != 0)
    {
        printf("%s", map->map[map->map_raw_count]);
    }
    return(0);
}
 
 