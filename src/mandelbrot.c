
#include "fractol.h"

int	mandelbrot(t_fractal_data *fractal_data)
{
	fractal_data->name = "Mandelbrot";
	fractal_init(fractal_data);
	events_init(fractal_data);
	data_init(fractal_data);
	fractal_render(fractal_data);
	mlx_loop(fractal_data->mlx_connection);
	return (0);
}
