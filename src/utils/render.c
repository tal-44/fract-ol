
#include "fractol.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	pixel_offset;

	pixel_offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(pixel_offset + img->img_pixels_ptr) = color;
}

// Z = Z^4 + C
static void	handle_pixel(t_fractal_data *fractal_data, int pixel_x, int pixel_y)
{
	int					i;
	t_complex_number	z;
	t_complex_number	c;
	t_complex_number	result;

	z.real = 0.0;
	z.imag = 0.0;
	c.real = map((double)pixel_x, -1.5, 1.5, 0.0, (double)WINDOW_WIDTH_DEFAULT)
		+ fractal_data->shift_x;
	c.imag = map((double)pixel_y, 1.5, -1.5, 0.0, (double)WINDOW_HEIGHT_DEFAULT)
		+ fractal_data->shift_y;
	i = -1;
	while (++i <= fractal_data->max_iterations)
	{
		result = complex_add(complex_exp(z, 4), c);
		if (complex_abs2(result) > (fractal_data->scape_radius
				* fractal_data->scape_radius))
		{
			my_pixel_put(&fractal_data->image, pixel_x, pixel_y,
				get_red_gradient(i, fractal_data->max_iterations));
			return ;
		}
		z = result;
	}
	my_pixel_put(&fractal_data->image, pixel_x, pixel_y, COLOR_DARK_PURPLE);
}

void	fractal_render(t_fractal_data *fractal_data)
{
	int	pixel_x;
	int	pixel_y;

	pixel_y = -1;
	while (++pixel_y < WINDOW_HEIGHT_DEFAULT)
	{
		pixel_x = -1;
		while (++pixel_x < WINDOW_WIDTH_DEFAULT)
		{
			handle_pixel(fractal_data, pixel_x, pixel_y);
		}
	}
	mlx_put_image_to_window(fractal_data->mlx_connection,
		fractal_data->mlx_window,
		fractal_data->image.img_ptr,
		0, 0);
}
