/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraksana <kraksana@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:30:00 by kraksana          #+#    #+#             */
/*   Updated: 2026/08/01 18:30:00 by kraksana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_view(t_fractal *fractal)
{
	fractal->max_iterations = MAX_ITERATIONS;
	fractal->needs_render = false;
	if (fractal->set == MANDELBROT)
	{
		fractal->min_real = -2.2;
		fractal->max_real = 1.2;
		fractal->min_imag = -1.7;
		fractal->max_imag = 1.7;
	}
	else
	{
		fractal->min_real = -2.0;
		fractal->max_real = 2.0;
		fractal->min_imag = -2.0;
		fractal->max_imag = 2.0;
	}
}

static int	create_image(t_fractal *fractal)
{
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->image)
	{
		ft_putstr_fd("Error: could not create image\n", 2);
		mlx_terminate(fractal->mlx);
		return (0);
	}
	if (mlx_image_to_window(fractal->mlx, fractal->image, 0, 0) < 0)
	{
		ft_putstr_fd("Error: could not display image\n", 2);
		mlx_terminate(fractal->mlx);
		return (0);
	}
	return (1);
}

int	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
	if (!fractal->mlx)
	{
		ft_putstr_fd("Error: could not initialize MLX42\n", 2);
		return (0);
	}
	return (create_image(fractal));
}
