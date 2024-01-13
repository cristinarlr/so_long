#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

int	close_red_cross_window(t_game *game)
{
	printf("closed window pressing red cross X\n");
	mlx_destroy_window(game->mlx, game->win);
	exit(NO_ERROR);
}

static int valid_movement(int new_row, int new_col, t_game *game)
{
    printf("dentro de valid_movement\n");
    if(game->map.map[new_row][new_col] == '0')
    {
        printf("dentro de valid_movement = '0'\n");
        game->map.map[new_row][new_col] = 'P';
        game->map.player_row = new_row;
        game->map.player_col = new_col;
        game->map.player_steps++;
    }
    if(game->map.map[new_row][new_col] == 'C')
    {
        printf("dentro de valid_movement = 'C'\n");
        //printf("MAPA ANTES\n");
        //print_map(game);
        game->map.map[new_row][new_col] = 'P';
        game->map.player_row = new_row;
        game->map.player_col = new_col;
        game->map.player_steps++;
        game->map.collectable_count--;
        //printf("MAPA DESPUES\n");
        //print_map(game);
    }
    if(game->map.map[new_row][new_col] == 'E')
    {
        printf("dentro de valid_movement = 'E'\n");
        if(game->map.collectable_count != 0)
            return(1);
        game->map.player_steps++;
        //hacer función de exit_game
        ft_printf("​\n 🙌​  🥦​🍆​🥕​🌽​🥬​🌶️  🙌​​\nEVERYTHING COLLECTED!\n 🙌​  🥦​🍆​🥕​🌽​🥬​🌶️  🙌​ \n\n");
        exit(0);
    }
    if(game->map.map[new_row][new_col] == '1')
        return(1);
    return(NO_ERROR);
}

static int do_move(int keycode, t_game *game)
{
    int current_row;
    int current_col;
    int scroll_row;
    int scroll_col;
    int feasible_move;

    current_row = game->map.player_row;
    current_col = game->map.player_col;
    scroll_row = 0;
    scroll_col = 0;
    printf("dentro de do_move\n");
    if(keycode == LEFT || keycode == A_LEFT )
        scroll_col = -1;
    if(keycode == RIGHT || keycode == D_RIGHT)
        scroll_col = 1;
    if(keycode == UP || keycode == W_UP)
        scroll_row = -1;
    if(keycode == DOWN || keycode == S_DOWN)
        scroll_row = 1;
    feasible_move = valid_movement(scroll_row + current_row, scroll_col + current_col, game);
    //if movement is not possible, only returns to give the possibility for a new keycode pressing
    if (feasible_move == 1)
        return(0);
    if(feasible_move == ERROR)
        return(ERROR);
    game->map.map[current_row][current_col] = '0';
    return(NO_ERROR);
}

int key_hook_control(int keycode, t_game *game)
{
    int feasible_move;

    ft_printf("dentro de key_hook_control\n");
    feasible_move = 0;
    printf("key hook - keycode: %d\n", keycode);
	if(keycode == ESC || keycode == Q_QUIT)
		close_red_cross_window(game);
	if(keycode == LEFT || keycode == A_LEFT || keycode == RIGHT || keycode == D_RIGHT 
    || keycode == UP || keycode == W_UP || keycode == DOWN || keycode == S_DOWN)
        feasible_move = do_move(keycode, game);
    if(feasible_move == 0)
        print_graphics_in_win(*game);
    return(0);
}