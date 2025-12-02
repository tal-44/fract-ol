#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// Creates gradient: divides iterations into 5 color stages
//		(red->yellow->green->cyan->blue->magenta)
// and fades between consecutive colors using bit shifts
unsigned int	get_red_gradient(int i, int max_iter)
{
	double	t;
	int		stage;
	double	fade;

	if (i >= max_iter)
		return (COLOR_BLACK);
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
