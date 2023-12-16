#include "../inc/get_next_line.h"
#include "../inc/so_long.h"

static int map_raws(char **argv, int fd)
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
    printf("\nmap_rows = %i\n", i);
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
        map->map[i] = get_next_line(fd);
        printf("map[%i] = %s", i, map->map[i]);
        i++;
        raw--;
    }
    map->map[i] = NULL;
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
}

static void is_it_squared(t_map *map)
{
    int i;
    int len;
    int cmp_len;
    char *trimmed;

    printf("\ndentro de is_it_squared\n");
    i = 0;
    trimmed = ft_strtrim(map->map[i], "\n");
    printf("trimmed: %s-test no nl", trimmed);
    if(map->map[i] != 0)
        len = ft_strlen(ft_strtrim(map->map[i], "\n"));
    while(map->map[i] != NULL)
    {
        cmp_len = ft_strlen(ft_strtrim(map->map[i], "\n"));
        //ver cómo manejo errores, si lo mando a una función si defino macros;
        if(len != cmp_len)
        {
            printf("\n** ERROR len != cmp_len **\n");
            printf("map[%i] = %s\n", i, map->map[i]);
            exit(-1);
        }
        i++;
    }
    map->map_column_count = len;
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
    map->map = malloc(sizeof(char **)*(raws+1));
    if(!map->map)
        return(-1);
    map->map_row_count = raws;
    //almacenar el mapa
    load_map(map, fd);
    //revisar que es cuadrado
    is_it_squared(map);
    //parsear para chequeo
    parse_map(map);
    //generar copia del mapa (porque ya está OK)
    copy_map(map);
    return(0);
}
 
 