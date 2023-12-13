#include "../inc/so_long.h"
#include "../mlx/mlx.h"
#include <math.h>

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
	printf("close window\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit(NO_ERROR);
	return(0);
}

int key_hook(int keycode, t_vars *vars)
{
	printf("key hook - keycode: %d\n", keycode);
	if(keycode == 53)
		close_window(vars);
	if(keycode == 0)
		printf("A is pressed!\n");
	return(0);
}

int mouse_hook(int keycode, t_vars *vars)
{
	(void) vars;
	printf("mouse_hook - keycode: %d\n", keycode);
	if(keycode == 2)
		printf("Mouse button 2 pressed!\n");
	return(0);
}

int mouse_position(int x, int y, t_vars *vars)
{
	(void) vars;
	printf("mouse_position - x: %d, y: %d\n", x, y);
	return(0);
}

void	draw_rainbow(t_vars *vars, int frame)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < 600)
	{
		x = 0;
		while (x < 800)
		{
			color = 0x000000 + ((int)(sin(frame * 0.1 + x * 0.01) * 127 + 128) << 16) +
								((int)(sin(frame * 0.1 + y * 0.01) * 127 + 128) << 8) +
								(int)(sin(frame * 0.1 + (x + y) * 0.01) * 127 + 128);
			mlx_pixel_put(vars->mlx, vars->win, x, y, color);
			x++;
		}
		y++;
	}
}


int render_next_frame(t_vars *vars)
{
	static int	frame = 0;
	t_vars		*data;

	data = (t_vars *)vars;
	mlx_clear_window(data->mlx, data->win);
	draw_rainbow(data, frame++);
	return (0);
}

int main(void)
{
		t_vars vars;
		void *img;
		void *bokchoi;

		vars.relative_path = "./xpm/Beet.xpm";
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 800, 600, "MOVING RAINBOW!");
		mlx_hook(vars.win, 2, 1L<<0, close, &vars); //key press event
		mlx_hook(vars.win, ON_DESTROY, 1L<<17, resize, &vars); //Window resize event
		mlx_hook(vars.win, ON_DESTROY, 1L<<17, close_window, &vars); //Window close event
		mlx_key_hook(vars.win, key_hook, &vars); //key press event
		mlx_mouse_hook(vars.win, mouse_hook, &vars); //mouse click event
		//mlx_hook(vars.win, ON_MOUSEMOVE, 1L<<6, mouse_position, &vars); //mouse move event
		//mlx_loop_hook(vars.mlx, render_next_frame, &vars); //rendering loop for animation (CLOUDS)
		img = mlx_xpm_file_to_image(vars.mlx, vars.relative_path, &vars.width, &vars.height);
		mlx_put_image_to_window(vars.mlx, vars.win, img, 400, 300);
		bokchoi = mlx_xpm_file_to_image(vars.mlx, "./xpm/Bok_Choy.xpm", &vars.width, &vars.height);
		mlx_put_image_to_window(vars.mlx, vars.win, bokchoi, 400, 200);
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
