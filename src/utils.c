#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

/* PARA PRINTEAR Y TESTEAR */

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

void print_map(t_game *game)
{
    int i = 0;
    int j = 0;
    int count = 1;

//ft_printf("Dentro de print_map:\n");
//ft_printf("game->map.map_row_count = %i\n", game->map.map_row_count);
//ft_printf("game->map.map_column_count = %i\n", game->map.map_column_count);
while(i < game->map.map_row_count)
    {
        while(j < game->map.map_column_count)
        {
            //printf("arr[%i][%i] = %c; count: %i\n", i, j, game->map.map[i][j], count);
            printf("%c", game->map.map[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
        count++;
    }
}

void print_map_cpy(t_game *game)
{
    int i = 0;
    int j = 0;
    int count = 1;

//ft_printf("Dentro de print_map_cpy:\n");
//ft_printf("game->map.map_row_count = %i\n", game->map.map_row_count);
//ft_printf("game->map.map_column_count = %i\n", game->map.map_column_count);
while(i < game->map.map_row_count)
    {
        while(j < game->map.map_column_count)
        {
            //printf("arr[%i][%i] = %c; count: %i\n", i, j, game->map.map[i][j], count);
            printf("%c", game->map.map_cpy[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
        count++;
    }
}

void print_data_structure(t_game *game)
{
    ft_printf("t_game:\n");
    ft_printf("game->map.map:\n");
    print_map(game);
    ft_printf("game->map.map_row_count:%i:\n", game->map.map_row_count);
    ft_printf("game->player_col:%i:\n", game->map.player_col);
    ft_printf("game->player_row:%i:\n", game->map.player_row);
    ft_printf("game->player_steps:%i:\n", game->map.player_steps);
    ft_printf("game->path_exit_count:%i:\n", game->map.path_exit_count);
    ft_printf("game->path_collectable_count:%i:\n", game->map.path_collectable_count);
    ft_printf("game->collectable_count:%i:\n", game->map.collectable_count);
}

void init_ds_map(t_map *map)
{
    map->map = NULL;
    map->map_cpy = NULL;
    map->map_row_count = 0;
    map->map_column_count = 0;
    map->flag_p = 0;
    map->flag_e = 0;
    map->flag_c = 0;
    map->player_col = 0;
    map->player_row = 0;
    map->player_steps = 0;
    map->path_exit_count = 0;
    map->path_collectable_count = 0;
    map->collectable_count = 0;
    map->player_front_img = NULL;
    map->player_back_img = NULL;
    map->player_left_img = NULL;
    map->player_right_img = NULL;
    map->wall_img = NULL;
    map->floor_img = NULL;
    map->collectable_img = NULL;
    map->exit_on_img = NULL;
    map->exit_off_img = NULL;
}

void print_ds_map(t_map *map)
{
    ft_printf("%p map->map\n", map->map);
    ft_printf("%p map->map_cpy\n", map->map_cpy);
    ft_printf("%p map->map_row_count\n", map->map_row_count);
    ft_printf("%p map->map_column_count\n", map->map_column_count);
    ft_printf("%p map->flag_e\n", map->flag_e);
    ft_printf("%p map->flag_p\n", map->flag_p);
    ft_printf("%p map->flag_c\n", map->flag_c);
    ft_printf("%p map->player_col\n", map->player_col);
    ft_printf("%p map->player_row\n", map->player_row);
    ft_printf("%p map->player_steps\n", map->player_steps);
    ft_printf("%p map->path_exit_count\n", map->path_exit_count);
    ft_printf("%p map->path_collectable_count\n", map->path_collectable_count);
    ft_printf("%p map->collectable_count\n", map->collectable_count);
    ft_printf("%p map->player_front_img\n", map->player_front_img);
    ft_printf("%p map->player_back_img\n", map->player_back_img);
    ft_printf("%p map->player_left_img\n", map->player_left_img);
    ft_printf("%p map->player_right_img\n", map->player_right_img);
    ft_printf("%p map->wall_img\n", map->wall_img);
    ft_printf("%p map->floor_img\n", map->floor_img);
    ft_printf("%p map->collectable_img\n", map->collectable_img);
    ft_printf("%p map->exit_on_img\n", map->exit_on_img);
    ft_printf("%p map->exit_off_img\n", map->exit_off_img);
}