#include "fractol.h"

/*
	There are two posible promtps
	./fractol mandelbrot
	./fractol julia <real part> <imaginary part>
*/
int	main(int argc, char **argv)
{
	t_fractal_data	fractal_data;

	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		return (mandelbrot(&fractal_data));
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		//	return (julia(ft_atof(argv[2]), ft_atof(argv[3])));
		return (0);
	}
	else
	{
		ft_printf("Usage: %s <fractal_type>", argv[0]);
		ft_printf("\nFractal types:\n");
		ft_printf("  mandelbrot\n");
		ft_printf("  julia <real part> <imaginary part>\n");
		return (EXIT_FAILURE);
	}
}
