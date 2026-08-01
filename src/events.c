/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraksana <kraksana@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:30:00 by kraksana          #+#    #+#             */
/*   Updated: 2026/08/01 18:30:00 by kraksana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_view(t_fractal *fractal, double factor)
{
	double	center_real;
	double	center_imag;
	double	real_range;
	double	imag_range;

	center_real = (fractal->min_real + fractal->max_real) / 2.0;
	center_imag = (fractal->min_imag + fractal->max_imag) / 2.0;
	real_range = (fractal->max_real - fractal->min_real) * factor;
	imag_range = (fractal->max_imag - fractal->min_imag) * factor;
	fractal->min_real = center_real - real_range / 2.0;
	fractal->max_real = center_real + real_range / 2.0;
	fractal->min_imag = center_imag - imag_range / 2.0;
	fractal->max_imag = center_imag + imag_range / 2.0;
}

static void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	double		factor;

	(void)xdelta;
	fractal = (t_fractal *)param;
	if (ydelta > 4.0)
		ydelta = 4.0;
	else if (ydelta < -4.0)
		ydelta = -4.0;
	if (ydelta == 0.0)
		return ;
	factor = pow(ZOOM_BASE, ydelta);
	zoom_view(fractal, factor);
	fractal->needs_render = true;
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractal->mlx);
}

static void	close_hook(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	mlx_close_window(fractal->mlx);
}

void	setup_hooks(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx, key_hook, fractal);
	mlx_scroll_hook(fractal->mlx, scroll_hook, fractal);
	mlx_close_hook(fractal->mlx, close_hook, fractal);
	mlx_loop_hook(fractal->mlx, render_loop, fractal);
}
