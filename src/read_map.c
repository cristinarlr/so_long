#include "../inc/get_next_line.h"
#include "../inc/so_long.h"

static int map_raws(char **argv, int fd)
{
    int i;
    char *line;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    while((line = get_next_line(fd)) != 0)
    {
        i++;
        printf("line = %s", line);
    }
    printf("\ni = %i\n", i);
    return(i);
}

void load_map(t_map *map, int fd)
{
    int i;
    int raw;

    printf("dentro de load_map\n");
    printf("map->map_raw_count = %i\n", map->map_raw_count);
    i = 0;
    raw = map->map_raw_count;
    while(raw > 0)
    {
        map->map[i] = get_next_line(fd);
        printf("map[%i] = %s", i, map->map[i]);
        i++;
        raw--;
    }
}

void copy_map(t_map *map)
{
    int i;

    printf("\ndentro de copy_map\n");
    i = 0;
    map->map_cpy = malloc(sizeof(char **)*map->map_raw_count);
    while(i < (map->map_raw_count))
    {
        map->map_cpy[i] = strdup(map->map[i]);
        printf("map->map_cpy[%i] = %s", i, map->map_cpy[i]);
        i++;
    }
}

int read_map(char **argv, t_map *map)
{
    int fd;
    int raws;
   
    printf("dentro de read_map\n");
    fd = open(argv[1], O_RDONLY);
    //sacar el tamaño del array map_size
    raws = map_raws(argv, fd);
    map = malloc(sizeof(t_map));
    //inicializar el array con el tamaño
    map->map = malloc(sizeof(char **)*raws);
    if(!map->map)
        return(-1);
    map->map_raw_count = raws;
    //almacenar el mapa
    load_map(map, fd);
    //revisar que es cuadrado
    //parsear para chequeo
    //generar copia del mapa (porque ya está OK)
    copy_map(map);
    
    
    return(0);
}
 
 