#include "fractol.h"


int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_valid_number(char *str)
{
	int has_digit;

	if (!str || !*str)
		return (0);
	has_digit = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str != '.' && *str != ',')
	{
		if (!ft_isdigit(*str))
			return (0);
		has_digit = 1;
		str++;
	}
	if (*str == '.' || *str == ',')
	{
		str++;
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (0);
			has_digit = 1;
			str++;
		}
	}
	return (has_digit);
}

static double	atod_helper(const char *str)
{
	double fractional_part;
	double divisor;

	fractional_part = 0.0;
	divisor = 1.0;
	while (*str)
	{
		fractional_part = fractional_part * 10.0 + (*str - '0');
		divisor *= 10.0;
		str++;
	}
	return (fractional_part / divisor);
}

/*
** Ascii to double
*/
double	atod(char *str)
{
	long integer_part;
	long prev;
	int sign;

	if (!str || !*str || !is_valid_number(str))
		return (0.0);
	integer_part = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str != '.' && *str != ',' && *str)
	{
		prev = integer_part;
		integer_part = integer_part * 10 + (*str - '0');
		if (integer_part < prev)
			return (0.0);
		str++;
	}
	if (*str == '.' || *str == ',')
		str++;
	return (sign * (integer_part + atod_helper(str)));
}
