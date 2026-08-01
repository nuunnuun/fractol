/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraksana <kraksana@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:30:00 by kraksana          #+#    #+#             */
/*   Updated: 2026/08/01 18:30:00 by kraksana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_valid_number(const char *str)
{
	int	i;
	int	dot;
	int	digit;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	dot = 0;
	digit = 0;
	while (str[i])
	{
		if (str[i] == '.' && !dot)
			dot = 1;
		else if (is_digit(str[i]))
			digit = 1;
		else
			return (0);
		i++;
	}
	return (digit);
}

static int	is_name(const char *name, const char *upper, const char *lower)
{
	return (!ft_strcmp(name, upper) || !ft_strcmp(name, lower));
}

int	parse_arguments(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && is_name(argv[1], "Mandelbrot", "mandelbrot"))
	{
		fractal->set = MANDELBROT;
		return (1);
	}
	if (argc == 4 && is_name(argv[1], "Julia", "julia")
		&& is_valid_number(argv[2]) && is_valid_number(argv[3]))
	{
		fractal->julia_real = ft_atod(argv[2]);
		fractal->julia_imag = ft_atod(argv[3]);
		if (!isfinite(fractal->julia_real)
			|| !isfinite(fractal->julia_imag))
		{
			print_usage();
			return (0);
		}
		fractal->set = JULIA;
		return (1);
	}
	print_usage();
	return (0);
}
