#include "../inc/get_next_line.h"
#include "../inc/so_long.h"

static int map_rows(char **argv, int fd)
{
    int i;
    char *line;

    printf("dentro de map_rows\n");
    i = 0;
    fd = open(argv[1], O_RDONLY);
    while((line = get_next_line(fd)) != 0)
    {
        i++;
        printf("line = %s", line);
    }
    printf("\nmap_rows = %i\n\n", i);
    return(i);
}

void load_map(t_map *map, int fd)
{
    int i;
    int raw;

    printf("dentro de load_map\n");
    printf("map->map_row_count = %i\n", map->map_row_count);
    i = 0;
    raw = map->map_row_count;
    while(raw > 0)
    {
        map->map[i] = ft_strtrim(get_next_line(fd), "\n");
        printf("map[%i] = %s", i, map->map[i]);
        i++;
        raw--;
    }
    map->map[i] = NULL;
    printf("map[%i] = %s\n\n", i, map->map[i]);
}

void copy_map(t_map *map)
{
    int i;

    printf("\ndentro de copy_map\n");
    i = 0;
    map->map_cpy = malloc(sizeof(char **)*(map->map_row_count + 1));
    while(i < (map->map_row_count))
    {
        map->map_cpy[i] = strdup(map->map[i]);
        printf("map->map_cpy[%i] = %s", i, map->map_cpy[i]);
        i++;
    }
    printf("\n^^^^^^^^^^^^COPIED MAP!^^^^^^^^^^^^\n");
}

static void is_it_squared(t_map *map)
{
    int i;
    int len;
    int cmp_len;

    printf("dentro de is_it_squared\n");
    i = 0;
    if(map->map[i] != 0)
        len = ft_strlen(map->map[i]);
    while(map->map[i] != NULL)
    {
        cmp_len = ft_strlen(map->map[i]);
        //ver cómo manejo errores, si lo mando a una función si defino macros;
        if(len != cmp_len)
        {
            printf("\n** ERROR NOT SQUARED len != cmp_len **\n");
            printf("map[%i] = %s\n", i, map->map[i]);
            exit(-1);
        }
        i++;
    }
    map->map_column_count = len;
    printf("^^^^^^^^^^^^IT'S SQUARED!^^^^^^^^^^^^\n");
}

int read_map(char **argv, t_map *map)
{
    int fd;
    int raws;
   
    printf("dentro de read_map\n");
    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
        return(ERROR);
    //extract the number of rows to create map array
    raws = map_rows(argv, fd);
    //initialize map array
    map->map = malloc(sizeof(char **)*(raws + 1));
    if(!map->map)
        return(ERROR);
    map->map_row_count = raws;
    //load map from .ber to array (inc nl)
    load_map(map, fd);
    close(fd);
    //verify that it's squared;
    is_it_squared(map);
    //generate map copy for flood fill parsing
    copy_map(map);
    //copy_map_new(map, map->map_cpy);
    //print_map(map->map_cpy);
    //parsing map values
    parse_map(map);
    return(0);
}
 
 