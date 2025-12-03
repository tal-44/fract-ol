#include "fractol.h"

/*
** Scales unscaled_value from old range to new range
** CONSERVING THE RATIO / PROPORTIONS
** Examples: 4 in [0, 10]  -->  40 in [0, 100]
**           4 in [0, 10]  -->  2.8 in [0, 7]
** We use this to map pixel coordinates [0, WIDTH] and [0, HEIGHT]
** to complex plane coordinates (e.g., [-2.0, 2.0])
*/
double	map(double unscaled_value, double old_min, double old_max)
{
	return ((2.0 - (-2.0)) * (unscaled_value - old_min) / (old_max - old_min)
		+ (-2.0));
}