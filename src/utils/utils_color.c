#include "fractol.h"

unsigned int	get_red_gradient(int i, int max_iter)
{
	double	t;
	int		stage;
	double	fade;

	if (i >= max_iter)
		return (COLOR_DARK_BLUE);
	t = (double)i / (double)max_iter * 5.0;
	stage = (int)t;
	fade = t - stage;
	if (stage == 0)
		return (COLOR_RED + ((int)(255 * fade) << 8));
	else if (stage == 1)
		return (COLOR_YELLOW - ((int)(255 * fade) << 16));
	else if (stage == 2)
		return (COLOR_GREEN + (int)(255 * fade));
	else if (stage == 3)
		return (COLOR_CYAN - ((int)(255 * fade) << 8));
	else if (stage == 4)
		return (COLOR_BLUE + ((int)(255 * fade) << 16));
	return (COLOR_MAGENTA);
}



// Dark blue → cyan → white
unsigned int	get_blue_gradient(int i, int max_iter)
{
	double	ratio;
	int		r;
	int		g;
	int		b;

	if (i >= max_iter)
		return (COLOR_BLACK);
	ratio = (double)i / (double)max_iter;
	r = (int)(ratio * 255.0);
	g = (int)(ratio * 255.0);
	b = (int)(51.0 + ratio * 204.0);
	return ((r << 16) | (g << 8) | b);
}

// Black → neon purple → neon pink
unsigned int	get_neon_gradient(int i, int max_iter)
{
	double	ratio;
	int		r;
	int		g;
	int		b;

	if (i >= max_iter)
		return (COLOR_BLACK);
	ratio = (double)i / (double)max_iter;
	if (ratio < 0.5)
	{
		ratio = ratio * 2.0;
		r = (int)(0x9B * ratio);
		g = (int)(0x30 * ratio);
		b = (int)(0xFF * ratio);
	}
	else
	{
		ratio = (ratio - 0.5) * 2.0;
		r = (int)(0x9B + (0xFF - 0x9B) * ratio);
		g = (int)((0x30 - 0x14) * (1.0 - ratio) + 0x14);
		b = (int)(0xFF - (0xFF - 0x93) * ratio);
	}
	return ((r << 16) | (g << 8) | b);
}

unsigned int	get_gradient(int i, int max_iter)
{
	if (GRADIENT == 1)
		return (get_red_gradient(i, max_iter));
	else if (GRADIENT == 2)
		return (get_blue_gradient(i, max_iter));
	else
		return (get_neon_gradient(i, max_iter));
}