
#include "fractol.h"

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handle, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handle,
		fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handle, fractal);
}

void	data_init(t_fractal *fractal)
{
	fractal->scape_radius_squared = 4.0;
	fractal->max_iterations = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	cleanup_and_exit(t_fractal *fractal, int stage)
{
	if (stage >= 2)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	if (stage >= 1)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
	exit(malloc_error());
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		exit(malloc_error());
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WINDOW_WIDTH_DEFAULT, WINDOW_HEIGHT_DEFAULT, fractal->name);
	if (!fractal->mlx_window)
		cleanup_and_exit(fractal, 1);
	fractal->image.img_ptr = mlx_new_image(fractal->mlx_connection,
			WINDOW_WIDTH_DEFAULT, WINDOW_HEIGHT_DEFAULT);
	if (!fractal->image.img_ptr)
		cleanup_and_exit(fractal, 2);
	fractal->image.img_pixels_ptr = mlx_get_data_addr(fractal->image.img_ptr,
			&fractal->image.bits_per_pixel, &fractal->image.line_length,
			&fractal->image.endian);
	events_init(fractal);
	data_init(fractal);
}
