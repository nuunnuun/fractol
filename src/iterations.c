/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraksana <kraksana@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:30:00 by kraksana          #+#    #+#             */
/*   Updated: 2026/08/01 18:30:00 by kraksana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	inside_mandelbrot(t_complex point)
{
	double	x;
	double	y_squared;
	double	q;

	x = point.real - 0.25;
	y_squared = point.imag * point.imag;
	q = x * x + y_squared;
	if (q * (q + x) <= 0.25 * y_squared)
		return (1);
	x = point.real + 1.0;
	if (x * x + y_squared <= 0.0625)
		return (1);
	return (0);
}

static void	set_start_values(t_fractal *fractal, t_complex point,
		t_complex *z, t_complex *c)
{
	if (fractal->set == MANDELBROT)
	{
		z->real = 0.0;
		z->imag = 0.0;
		*c = point;
	}
	else
	{
		*z = point;
		c->real = fractal->julia_real;
		c->imag = fractal->julia_imag;
	}
}

int	fractal_iterations(t_fractal *fractal, t_complex point)
{
	t_complex	z;
	t_complex	c;
	double		real_squared;
	double		imag_squared;
	int			iterations;

	if (fractal->set == MANDELBROT && inside_mandelbrot(point))
		return (fractal->max_iterations);
	set_start_values(fractal, point, &z, &c);
	real_squared = z.real * z.real;
	imag_squared = z.imag * z.imag;
	iterations = 0;
	while (real_squared + imag_squared <= 4.0
		&& iterations < fractal->max_iterations)
	{
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = real_squared - imag_squared + c.real;
		real_squared = z.real * z.real;
		imag_squared = z.imag * z.imag;
		iterations++;
	}
	return (iterations);
}
