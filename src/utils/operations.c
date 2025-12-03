#include "fractol.h"

t_complex_number	complex_add(t_complex_number a, t_complex_number b)
{
	t_complex_number	result;

	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return (result);
}

t_complex_number	complex_mult(t_complex_number a, t_complex_number b)
{
	t_complex_number	result;

	result.real = (a.real * b.real) - (a.imag * b.imag);
	result.imag = (a.real * b.imag) + (a.imag * b.real);
	return (result);
}

t_complex_number	complex_exp(t_complex_number z, int exponent)
{
	t_complex_number	result;
	int					i;

	result.real = 1.0;
	result.imag = 0.0;
	i = 0;
	while (i < exponent)
	{
		result = complex_mult(result, z);
		i++;
	}
	return (result);
}

t_complex_number	complex_square(t_complex_number z)
{
	t_complex_number	result;

	result.real = z.real * z.real - z.imag * z.imag;
	result.imag = 2.0 * z.real * z.imag;
	return (result);
}

double	complex_abs2(t_complex_number z)
{
	return (z.real * z.real + z.imag * z.imag);
}
