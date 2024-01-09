#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void load_xpm_to_data_structure(t_map *map)
{
    int width;
    int height;
    
    map->collectable_img = mlx_xpm_file_to_image(map->mlx, "./xpm/Bok_Choy.xpm", &width, &height);
    map->player_img= mlx_xpm_file_to_image(map->mlx, "./xpm/fox.xpm", &width, &height);
    map->wall_img= mlx_xpm_file_to_image(map->mlx, "./xpm/wall.xpm", &width, &height);
    map->floor_img= mlx_xpm_file_to_image(map->mlx, "./xpm/floor.xpm", &width, &height);
    map->floor_img= mlx_xpm_file_to_image(map->mlx, "./xpm/floor.xpm", &width, &height);
}

void print_xpm_on_map(t_map *map)
{
    (void) map;

    return ;
}

void print_graphics_in_win(t_map *map)
{
    load_xpm_to_data_structure(map);
    print_xpm_on_map(map);
}