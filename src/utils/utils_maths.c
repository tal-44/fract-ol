#include "fractol.h"

// scales unscaled_value from old range
// to new range CONSERVING THE RATIO / PROPORTIONS
// 4 in 0, 10  -->   40 in 0, 100
// 4 in 0, 10  -->   2.8 in 0, 7
//
// We have to use it because original pixel coordinates
// are in [0, WIDTH] and [0, HEIGHT]
// but we need them in [-3.0, 3.0] and [-3.0, 3.0] (for example)
double	map(double unscaled_value, double new_min,
	double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_value - old_min)
		/ (old_max - old_min) + new_min);
}