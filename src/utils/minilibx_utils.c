
#include "fractol.h"

void	events_init(t_fractal_data *fractal_data)
{
	mlx_hook(fractal_data->mlx_window,
		KeyPress,
		KeyPressMask,
		key_handle,
		fractal_data);
	mlx_hook(fractal_data->mlx_window,
		ButtonPress,
		ButtonPressMask,
		mouse_handle,
		fractal_data);
	mlx_hook(fractal_data->mlx_window,
		DestroyNotify,
		StructureNotifyMask,
		close_handle,
		fractal_data);
}

void	data_init(t_fractal_data *fractal_data)
{
	fractal_data->scape_radius = 3.0;
	fractal_data->max_iterations = 100;
	fractal_data->shift_x = 0.0;
	fractal_data->shift_y = 0.0;
}

void	fractal_init(t_fractal_data *fractal_data)
{
	fractal_data->mlx_connection = mlx_init();
	if (!fractal_data->mlx_connection)
		exit(malloc_error());
	fractal_data->mlx_window = mlx_new_window(fractal_data->mlx_connection,
			WINDOW_WIDTH_DEFAULT, WINDOW_HEIGHT_DEFAULT, fractal_data->name);
	if (!fractal_data->mlx_window)
	{
		mlx_destroy_display(fractal_data->mlx_connection);
		free(fractal_data->mlx_connection);
		exit(malloc_error());
	}
	fractal_data->image.img_ptr = mlx_new_image(fractal_data->mlx_connection,
			WINDOW_WIDTH_DEFAULT, WINDOW_HEIGHT_DEFAULT);
	if (!fractal_data->image.img_ptr)
	{
		mlx_destroy_window(fractal_data->mlx_connection,
			fractal_data->mlx_window);
		mlx_destroy_display(fractal_data->mlx_connection);
		free(fractal_data->mlx_connection);
		exit(malloc_error());
	}
	fractal_data->image.img_pixels_ptr = mlx_get_data_addr(
			fractal_data->image.img_ptr,
			&fractal_data->image.bits_per_pixel,
			&fractal_data->image.line_length, &fractal_data->image.endian);
}
