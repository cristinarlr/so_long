#ifndef SO_LONG_H
# define SO_LONG_H

/* ---- NEW ---- */
/*# include <mlx.h>*/
# include <fcntl.h>

/* --- LIBRARIES --- */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
#include <sys/time.h>
#include <errno.h>

/* ---------------- PATH ---------------- */
# include "../src/libft/libft.h"
# include "../src/ft_printf/ft_printf.h"
# include "../mlx/mlx.h"
/*# include "../src/Gnl/include/get_next_line.h"*/

/* ----- RESOLUTIONS ----- */
# define RESOLUTION_H	32
# define RESOLUTION_W	32

/* ----- CONSTANTS ----- */
enum e_exit_code{
	ERROR = -1,
	NO_ERROR = 0	
};

enum events
{
    ON_KEYPRESS = 2,
    ON_KEYRELEASE = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum keycodes
{
    L_CLICK = 1,
    R_CLICK = 2,
    M_CLICK = 3,
    SCROLL_UP = 4,
    SCROLL_DOWN = 5,
    A_KEY = 0,
	S_KEY,
	D_KEY,
	W_KEY = 13,
	ESC = 53,
	LEFT = 123,
	RIGHT,
	DOWN,
	UP
};

/* ----- STRUCT ----- */
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	char 	**map;
	char 	**map_cpy;
	int		map_row_count;
	int 	map_column_count;
	int		player_col;
	int		player_row;
	int		player_steps;
	int		path_exit_count;
	int		path_collectable_count;
	int		collectable_count;
	//void	*mlx;
	//void	*win;
	void	*player_img;
	void	*wall_img;
	void	*floor_img;
	void	*collectable_img;
	void	*exit_on_img;
	void	*exit_off_img;
}t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*relative_path;
	//int		width;
	//int		height;
	int		key_pressed;
	t_map	map;
}	t_game;

/* ----- FUNCTIONS ----- */

int read_map(char **argv, t_map *map);
void parse_map (t_map *map);
void print_graphics_in_win(t_game game);

/* ----- FUNCTIONS UTILS WHILE PROGRAMING----- */
void print_map (char **arr);
void print_string(char *s);

#endif