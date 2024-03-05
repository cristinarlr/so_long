/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:27:54 by crramire          #+#    #+#             */
/*   Updated: 2024/02/29 10:50:33 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ---- NEW ---- */
/* # include <mlx.h> */
# include <fcntl.h>

/* --- LIBRARIES --- */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include <errno.h>

/* ---------------- PATH ---------------- */
# include "../src/libft/libft.h"
# include "../src/ft_printf/ft_printf.h"
# include "../mlx/mlx.h"

/* ----- RESOLUTIONS ----- */
# define RESOLUTION_H	32
# define RESOLUTION_W	32

/* ----- XPM PATH ----- */
# define XPM_1 "./xpm/beet_on_floor.xpm"
# define XPM_2 "./xpm/elf_front.xpm"
# define XPM_3 "./xpm/elf_back.xpm"
# define XPM_4 "./xpm/elf_left.xpm"
# define XPM_5 "./xpm/elf_right.xpm"
# define XPM_6 "./xpm/wall.xpm"
# define XPM_7 "./xpm/floor.xpm"
# define XPM_8 "./xpm/exit_on.xpm"
# define XPM_9 "./xpm/exit_off.xpm"

/* ----- MESSAGES ----- */
# define ERRORMSG_1	"Error: Invalid map format, only .ber are allowed"
# define ERRORMSG_2 "Error: Expecting a valid input, verify exe arguments"
# define ERRORMSG_3 ": Problem reading file"
# define ERRORMSG_4 ": Memory allocation problem"
# define ERRORMSG_5 ": Map is not squared"
# define ERRORMSG_5_1 ": Map size not valid. Please try smaller map"
# define ERRORMSG_6 ": Memory allocation problem"
# define ERRORMSG_7 ": Invalid map values.\n\
\t>> Only 1, 0, P, E and C are allowed.\n\
\t>> Map frame has to be built with 1 values.\n"
# define ERRORMSG_8 ": Invalid map values.\n\
\t>> Only one player (P), one exit (E) allowed\n\
\t>> At least one collectable (C).\n"
# define ERRORMSG_9 ": Invalid path.\n\
\t>> Impossible to collect everything or access to exit.\n"
# define ERRORMSG_10 ": Image file not found"
# define SUCCESSMSG "​🥦​🍆​🥕​🌽​🥬​🌶️​ EVERYTHING COLLECTED! 🥦​🍆​🥕​🌽​🥬​🌶️\n"

/* ----- CONSTANTS ----- */
enum e_exit_code
{
	ERROR = -1,
	NO_ERROR = 0
};

enum e_events
{
	ON_KEYPRESS = 2,
	ON_KEYRELEASE = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_keycodes
{
	L_CLICK = 1,
	R_CLICK = 2,
	M_CLICK = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
	A_LEFT = 0,
	S_DOWN,
	D_RIGHT,
	W_UP = 13,
	Q_QUIT = 12,
	ESC = 53,
	LEFT = 123,
	RIGHT,
	DOWN,
	UP
};

/* ----- STRUCT ----- */

typedef struct s_map
{
	char	**map;
	char	**map_cpy;
	int		map_row_count;
	int		map_column_count;
	int		flag_p;
	int		flag_e;
	int		flag_c;
	int		player_col;
	int		player_row;
	int		player_steps;
	int		path_exit_count;
	int		path_collectable_count;
	int		collectable_count;
	void	*player_front_img;
	void	*player_back_img;
	void	*player_left_img;
	void	*player_right_img;
	void	*wall_img;
	void	*floor_img;
	void	*collectable_img;
	void	*exit_on_img;
	void	*exit_off_img;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		key_pressed;
	t_map	map;
}	t_game;

/* ----- FUNCTIONS ----- */

int		read_map(char **argv, t_map *map, t_game *game);
void	parse_map(t_map *map, t_game *game);
void	print_graphics_in_win(t_game game);
int		key_hook_control(int keycode, t_game *game);
int		close_red_cross_window(t_game *game);
int		print_error_do_exit(char *error_message, t_game *game);
void	free_map(char **map);
void	init_data_map(t_map *map);
int		check_values(t_map *map);
int		min_pec_char(t_map *map);
void	print_xpm_on_map(t_game *game);

#endif
