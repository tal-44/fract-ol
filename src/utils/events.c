
#include "fractol.h"

int	key_handle(int keysym, t_fractal_data *fractal_data)
{
	if (keysym == XK_Escape)
		close_handle(fractal_data);
	else if (keysym == XK_Left || keysym == XK_a)
		fractal_data->shift_x += 0.5;
	else if (keysym == XK_Right || keysym == XK_d)
		fractal_data->shift_x -= 0.5;
	else if (keysym == XK_Up || keysym == XK_w)
		fractal_data->shift_y -= 0.5;
	else if (keysym == XK_Down || keysym == XK_s)
		fractal_data->shift_y += 0.5;
	else if (keysym == XK_plus)
		fractal_data->max_iterations += 10;
	else if (keysym == XK_minus)
		fractal_data->max_iterations -= 10;
	fractal_render(fractal_data);
	return (0);
}

// int mouse_handle(int button, int x, int y, t_fractal_data *fractal_data)
int	mouse_handle(int button, t_fractal_data *fractal_data)
{
	if (button == 4)
		fractal_data->scape_radius *= 0.9;
	else if (button == 5)
		fractal_data->scape_radius /= 0.9;
	fractal_render(fractal_data);
	return (0);
}

int	close_handle(t_fractal_data *fractal_data)
{
	ft_printf("Window close event received. Exiting...\n");
	mlx_destroy_image(fractal_data->mlx_connection,
		fractal_data->image.img_ptr);
	mlx_destroy_window(fractal_data->mlx_connection, fractal_data->mlx_window);
	mlx_destroy_display(fractal_data->mlx_connection);
	free(fractal_data->mlx_connection);
	exit(0);
	return (0);
}
