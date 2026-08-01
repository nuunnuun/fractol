/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraksana <kraksana@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:30:00 by kraksana          #+#    #+#             */
/*   Updated: 2026/08/01 18:45:00 by kraksana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	render_row(t_fractal *fractal, uint32_t y,
		t_complex point, double real_step)
{
	uint32_t	x;
	int			iterations;

	x = 0;
	while (x < WIDTH)
	{
		iterations = fractal_iterations(fractal, point);
		mlx_put_pixel(fractal->image, x, y,
			get_color(iterations, fractal->max_iterations));
		point.real += real_step;
		x++;
	}
}

void	render_fractal(t_fractal *fractal)
{
	uint32_t	y;
	t_complex	point;
	double		real_step;
	double		imag_step;

	real_step = (fractal->max_real - fractal->min_real) / (WIDTH - 1);
	imag_step = (fractal->max_imag - fractal->min_imag) / (HEIGHT - 1);
	y = 0;
	point.imag = fractal->max_imag;
	while (y < HEIGHT)
	{
		point.real = fractal->min_real;
		render_row(fractal, y, point, real_step);
		point.imag -= imag_step;
		y++;
	}
}
