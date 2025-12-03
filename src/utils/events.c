
#include "fractol.h"

int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handle(fractal);
	else if (keysym == XK_Left || keysym == XK_a)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right || keysym == XK_d)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up || keysym == XK_w)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down || keysym == XK_s)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->max_iterations += 10;
	else if (keysym == XK_minus && fractal->max_iterations > 10)
		fractal->max_iterations -= 10;
	else
		return (0);
	fractal_render(fractal);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	double	zoom_multiplier;
	double	mouse_re;
	double	mouse_im;

	if (button == 4)
		zoom_multiplier = 0.95;
	else if (button == 5)
		zoom_multiplier = 1.05;
	else
		return (0);
	mouse_re = (map((double)x, -1.5, 1.5, 0.0, (double)WINDOW_WIDTH_DEFAULT)
			* fractal->zoom) + fractal->shift_x;
	mouse_im = (map((double)y, 1.5, -1.5, 0.0, (double)WINDOW_HEIGHT_DEFAULT)
			* fractal->zoom) + fractal->shift_y;
	fractal->zoom *= zoom_multiplier;
	fractal->shift_x = mouse_re - (map((double)x, -1.5, 1.5, 0.0,
				(double)WINDOW_WIDTH_DEFAULT) * fractal->zoom);
	fractal->shift_y = mouse_im - (map((double)y, 1.5, -1.5, 0.0,
				(double)WINDOW_HEIGHT_DEFAULT) * fractal->zoom);
	fractal_render(fractal);
	return (0);
}

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}