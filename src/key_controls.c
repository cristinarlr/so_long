#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

int	close_red_cross_window(t_game *game)
{
	printf("close window\n");
	mlx_destroy_window(game->mlx, game->win);
	exit(NO_ERROR);
}

static int valid_movement(int row, int col, t_game *game)
{
    if(game->map.map[row][col] == '0')
    {
        game->map.map[row][col] = 'P';
        game->map.player_row = row;
        game->map.player_col = col;
        game->map.player_steps++;
    }
    if(game->map.map[row][col] == 'C')
    {
        game->map.map[row][col] = 'P';
        game->map.player_row = row;
        game->map.player_col = col;
        game->map.player_steps++;
        game->map.collectable_count--;
    }
    if(game->map.map[row][col] == 'E')
    {
        if(game->map.collectable_count != 0)
            return(NO_ERROR);
        game->map.player_steps++;
        //hacer función de exit_game
        ft_printf("EVERYTHING COLLECTED!\n");
    }
    return(NO_ERROR);
}

static int do_move(int keycode, t_game *game)
{
    int scroll_row;
    int scroll_col;
    int feasible_move;

    scroll_row = 0;
    scroll_col = 0;
    if(keycode == LEFT || keycode == A_LEFT )
        scroll_col = -1;
    if(keycode == RIGHT || keycode == D_RIGHT)
        scroll_col = 1;
    if(keycode == UP || keycode == W_UP)
        scroll_row = -1;
    if(keycode == DOWN || keycode == S_DOWN)
        scroll_row = 1;
    feasible_move = valid_movement(scroll_row + game->map.player_row, scroll_col + game->map.player_col, game);
    //if movement is not possible, only returns to give the possibility for a new keycode pressing
    if(feasible_move == ERROR)
        return(ERROR);
    game->map.map[game->map.player_row][game->map.player_col] = '0';
    return(NO_ERROR);
}

int key_hook_control(int keycode, t_game *game)
{
    int feasible_move;

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