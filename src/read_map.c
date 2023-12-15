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
    printf("map->map_row_count = %i\n", map->map_raw_count);
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

void print_string(char *s)
{
    int i = 0;
    int count = 1;

    printf("Veamos la string:\n");
    while(s[i])
    {
        printf("s[%i] = %c; count: %i\n", i, s[i], count);
        i++;
        count++;
    }
    printf("s[%i] = NULL; count: %i\n", i, count);
}

int strlen_nl_adapted(char *s)
{
    int i;

    printf("strlen_nl_adapted\n");
    i = 0;
    if(!s)
        return(0);
    while(s[i] || s[i]=='\n')
        i++;
    if(s[i-1] == '\0')
        i++;
    return(i-1);
}

void is_it_squared(t_map *map)
{
    int i;
    int len;
    int cmp_len;
    char *trimmed;

    printf("\ndentro de is_it_squared\n");
    i = 0;
    trimmed = ft_strtrim(map->map[i], "\n");
    printf("trimmed: %s-test\n", trimmed);
    if(map->map[i] != 0)
        len = ft_strlen(ft_strtrim(map->map[i], "\n"));
    printf("1\n");
    printf("map[4] = %s\n", map->map[4]);
    while(map->map[i])
    {
        printf("2\n");
        printf("map[%i] = %s\n", i, map->map[i]);
        cmp_len = ft_strlen(ft_strtrim(map->map[i], "\n"));
        //printf("map[%i] = %s", i, map->map[i]);
        //printf("compare:len = %i, cmp_len = %i\n", len, cmp_len);
        //print_string(map->map[i]);
        //ver cómo manejo errores, si lo mando a una función si defino macros;
        if(len != cmp_len)
        {
            printf("\n***** Dentro de is_it_squared IF len != cmp_len *****\n");
            printf("map[%i] = %s\n", i, map->map[i]);
            //printf("IF compare: len = %i, cmp_len = %i\n", len, cmp_len);
            //print_string(map->map[i]);
            exit(-1);
        }
        printf("3\n");
        i++;
        printf("i = %i\n", i);
        printf("4\n");
    }
    printf("2. len = %i, cmp_len = %i\n", len, cmp_len);
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
    is_it_squared(map);
    //parsear para chequeo
    //generar copia del mapa (porque ya está OK)
    copy_map(map);
    
    
    return(0);
}
 
 