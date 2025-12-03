
#include "fractol.h"

int	malloc_error(void)
{
	ft_printf("Error: Memory allocation failed.\n");
	return (ERROR_MALLOC_FAILED);
}

int	close_handle(t_fractal *fractal)
{
	if (!fractal)
		exit(EXIT_SUCCESS);
	if (fractal->image.img_ptr && fractal->mlx_connection)
		mlx_destroy_image(fractal->mlx_connection, fractal->image.img_ptr);
	if (fractal->mlx_window && fractal->mlx_connection)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	if (fractal->mlx_connection)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
	exit(EXIT_SUCCESS);
}