

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../src/utils/libft/ft_printf/ft_printf.h"
# include "../src/utils/libft/libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WINDOW_WIDTH_DEFAULT 800
# define WINDOW_HEIGHT_DEFAULT 800

# define ERROR_MALLOC_FAILED 1

/* Basic colors */
# define COLOR_BLACK 0x000000
# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF

/* Nice vivid colors */
# define COLOR_YELLOW 0xFFFF00
# define COLOR_CYAN 0x00FFFF
# define COLOR_MAGENTA 0xFF00FF
# define COLOR_ORANGE 0xFF8800
# define COLOR_PURPLE 0x8000FF
# define COLOR_PINK 0xFF66CC
# define COLOR_TURQUOISE 0x00CC99

/* Dark tones */
# define COLOR_DARK_RED 0x660000
# define COLOR_DARK_GREEN 0x003300
# define COLOR_DARK_BLUE 0x000033
# define COLOR_DARK_PURPLE 0x330033
# define COLOR_DARK_ORANGE 0x662200

/* Soft / pastel */
# define COLOR_SOFT_BLUE 0x6699FF
# define COLOR_SOFT_GREEN 0x99FF99
# define COLOR_SOFT_YELLOW 0xFFF599
# define COLOR_SOFT_PURPLE 0xCC99FF
# define COLOR_SOFT_PINK 0xFF99CC

/* Neon / vivid */
# define COLOR_NEON_GREEN 0x39FF14
# define COLOR_NEON_BLUE 0x1E90FF
# define COLOR_NEON_PINK 0xFF1493
# define COLOR_NEON_PURPLE 0x9B30FF
# define COLOR_GOLD 0xFFD700
# define COLOR_SILVER 0xC0C0C0

typedef struct s_complex_number
{
	double			real;
	double			imag;
}					t_complex_number;

typedef struct s_img
{
	void			*img_ptr;
	char			*img_pixels_ptr;
	int				bits_per_pixel;
	int				endian;
	int				line_length;
}					t_img;

typedef struct s_fractal_data
{
	char			*name;
	double			scape_radius;
	int				max_iterations;
	void			*mlx_connection;
	void			*mlx_window;
	t_img			image;
	double			shift_x;
	double			shift_y;
}					t_fractal_data;

int					main(int argc, char **argv);

// Fractal functions
int					mandelbrot(t_fractal_data *fractal_data);
void				fractal_init(t_fractal_data *fractal_data);
void				fractal_render(t_fractal_data *fractal_data);
void				events_init(t_fractal_data *fractal_data);
void				data_init(t_fractal_data *fractal_data);

// Complex number operations
t_complex_number	complex_add(t_complex_number a, t_complex_number b);
t_complex_number	complex_mult(t_complex_number a, t_complex_number b);
t_complex_number	complex_exp(t_complex_number z, int exponent);
double				complex_abs2(t_complex_number z);
t_complex_number	complex_conjugate(t_complex_number z);

// Error handling
int					malloc_error(void);

// Event handling
int					key_handle(int keycode, t_fractal_data *fractal_data);
// int mouse_handle(int button, int x, int y, t_fractal_data *fractal_data)
int					mouse_handle(int button, t_fractal_data *fractal_data);
int					close_handle(t_fractal_data *fractal_data);

// Utility functions
int					ft_strcmp(const char *s1, const char *s2);
double				map(double unscaled_value, double new_min, double new_max,
						double old_min, double old_max);
unsigned int		get_red_gradient(int i, int max_iter);

#endif
