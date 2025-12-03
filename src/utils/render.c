
#include "fractol.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	pixel_offset;

	pixel_offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(pixel_offset + img->img_pixels_ptr) = color;
}

static void	mandelbrot_or_julia(t_fractal *fractal, t_complex_number *c, t_complex_number *z)
{
	if (!ft_strcmp(fractal->name, "Julia"))
	{
		c->real = fractal->julia_x;
		c->imag = fractal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->imag = z->imag;
	}
}

// Mandelbrot set
// Z = Z^2 + C
//
// Jualia set
// Z = Z^2 + pixel_point
static void	handle_pixel(t_fractal *fractal, int pixel_x, int pixel_y)
{
	int					i;
	t_complex_number	z;
	t_complex_number	c;

	z.real = (map((double)pixel_x, -1.5, 1.5, 0.0, (double)WINDOW_WIDTH_DEFAULT))
			* fractal->zoom + fractal->shift_x;
	z.imag = (map((double)pixel_y, 1.5, -1.5, 0.0, (double)WINDOW_HEIGHT_DEFAULT)
			* fractal->zoom) + fractal->shift_y;
	mandelbrot_or_julia(fractal, &c, &z);
	i = 0;
	while (i < fractal->max_iterations)
	{
		z = complex_add(complex_square(z), c);
		if (complex_abs2(z) > fractal->scape_radius * fractal->scape_radius)
		{
			my_pixel_put(&fractal->image, pixel_x, pixel_y, get_gradient(i,
					fractal->max_iterations));
			return ;
		}
		i++;
	}
	my_pixel_put(&fractal->image, pixel_x, pixel_y, COLOR_BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	pixel_x;
	int	pixel_y;

	pixel_y = -1;
	while (++pixel_y < WINDOW_HEIGHT_DEFAULT)
	{
		pixel_x = -1;
		while (++pixel_x < WINDOW_WIDTH_DEFAULT)
		{
			handle_pixel(fractal, pixel_x, pixel_y);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->image.img_ptr, 0, 0);
}
