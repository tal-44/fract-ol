#include "fractol.h"


static int	mandelbrot(t_fractal *fractal)
{
	fractal->name = "Mandelbrot";
	fractal_init(fractal);
	fractal_render(fractal);
	mlx_loop(fractal->mlx_connection);
	return (0);
}


static int	julia(t_fractal *fractal)
{
	fractal->name = "Julia";
	fractal_init(fractal);
	fractal_render(fractal);
	mlx_loop(fractal->mlx_connection);
	return (0);
}

/*
	There are two possible prompts:
	./fractol mandelbrot
	./fractol julia <real part> <imaginary part>
*/
int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		return (mandelbrot(&fractal));
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		if (!is_valid_number(argv[2]) || !is_valid_number(argv[3]))
		{
			ft_printf("Error: Invalid numeric parameters for Julia set.\n");
			return (EXIT_FAILURE);
		}
		fractal.julia_x = atod(argv[2]);
		fractal.julia_y = atod(argv[3]);
		return (julia(&fractal));
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
