#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void load_xpm_to_data_structure(t_game game)
{
    int width;
    int height;
    
    ft_printf("load_xpm_to_data_structure\n");
    game.map.collectable_img = mlx_xpm_file_to_image(game.mlx, "./xpm/Bok_Choy.xpm", &width, &height);
    game.map.player_img= mlx_xpm_file_to_image(game.mlx, "./xpm/mysprite.xpm", &width, &height);
    game.map.wall_img= mlx_xpm_file_to_image(game.mlx, "./xpm/wall.xpm", &width, &height);
    game.map.floor_img= mlx_xpm_file_to_image(game.mlx, "./xpm/Beet.xpm", &width, &height);
    game.map.exit_on_img= mlx_xpm_file_to_image(game.mlx, "./xpm/Broccoli.xpm", &width, &height);
    //game.map.exit_off_img= mlx_xpm_file_to_image(game.mlx, "./xpm/exit_on.xpm", &width, &height);
}

void select_square_grid_image(t_game game, int row, int col)
{
    ft_printf("select_square_grid_image [%i][%i] = %c\n", row, col, game.map.map[row][col]);
    if(game.map.map[row][col] == '1')
        mlx_put_image_to_window(game.mlx, game.win, game.map.wall_img, col * RESOLUTION_W, row * RESOLUTION_H);
    else if(game.map.map[row][col] == '0')
        mlx_put_image_to_window(game.mlx, game.win, game.map.floor_img, col * RESOLUTION_W, row * RESOLUTION_H);
    else if(game.map.map[row][col] == 'P')
        mlx_put_image_to_window(game.mlx, game.win, game.map.player_img, col * RESOLUTION_W, row * RESOLUTION_H);
    else if(game.map.map[row][col] == 'E')
        mlx_put_image_to_window(game.mlx, game.win, game.map.exit_on_img, col * RESOLUTION_W, row * RESOLUTION_H);
    else if(game.map.map[row][col] == 'C')
        mlx_put_image_to_window(game.mlx, game.win, game.map.collectable_img, col * RESOLUTION_W, row * RESOLUTION_H);
}

void print_xpm_on_map(t_game game)
{
    int row;
    int col;

    row = 0;
    while (row < game.map.map_row_count)
    {
        col = 0;
        while (col < game.map.map_column_count)
        {
            select_square_grid_image(game, row, col);
            col++;
        }
        row++;
    }

    return ;
}

void print_graphics_in_win(t_game game)
{
    ft_printf("dentro de print_graphics_in_win\n");
    load_xpm_to_data_structure(game);
    print_xpm_on_map(game);
}