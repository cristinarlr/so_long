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

/* ---------------- PATH ---------------- */
# include "../src/libft/libft.h"
# include "../src/ft_printf/ft_printf.h"
# include "../mlx/mlx.h"
/*# include "../src/Gnl/include/get_next_line.h"*/

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
	int		map_raw_count;
	int 	map_column_count;
}t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*relative_path;
	int		width;
	int		height;
	int		key_pressed;
}	t_vars;

/* ----- FUNCTIONS ----- */

int read_map(char **argv, t_map *map);

#endif