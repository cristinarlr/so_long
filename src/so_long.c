/*#include <mlx.h>*/
#include <stdio.h>
#include <stdlib.h>
#include "../inc/so_long.h"
#include "../mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		key_pressed;
	struct	timeval key_press_time;
}	t_vars;

int resize(int width, int height, t_vars *vars)
{
	(void)	width;
	(void)	height;
	(void)	vars;

	printf("Window resized: %dx%d\n", width, height);
	return(0);
	
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return(0);
}

int close(int keycode, t_vars *vars)
{
	if(keycode == 53)
		close_window(vars);
	return(0);
}

int	key_press(int keycode, t_vars *vars)
{
	vars->key_pressed = keycode;
	gettimeofday(&(vars->key_pressed), NULL);
	return(0);
}

int	key_release(int keycode, t_vars *vars)
{
	if(keycode == vars->key_pressed)
	{
		struct timeval current_time;
		gettimeofdaay(&current_time, NULL);
		double elaapsed_time = (current_time.tv_sec - vars->key_press_time.tv_sec) + (current_time.tv_usec - vars -> key_press_time.tv_usec) / 1000000.0;
		if(elaapsed_time > 2.0)
			printf("Key %d pressed for %.2f seconds\n", keycode, elaapsed_time);
	}
}

int main(void)
{
		t_vars vars;

		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 1920, 1080, "MY GAME!");
		mlx_hook(vars.win, 2, 1L<<0, close, &vars); //key press event
		mlx_hook(vars.win, 17, 1L<<17, resize, &vars); //Window resize event
		mlx_hook(vars.win, 17, 1L<<17, close_window, &vars); //Window close event
		mlx_loop_hook(vars.mlx, loop_hook, &vars); //Continuous loop hook
		mlx_loop(vars.mlx);
}

/*void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	printf("color: %d\n", color);
	printf("dst: %s\n", dst);
	*(unsigned int*)dst = color;
	printf("color: %d\n", color);
	printf("dst: %s\n", dst);
}*/

/*int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00ff0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/
