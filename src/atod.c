/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
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

static double	fraction_value(const char *str)
{
	double	value;
	double	place;

	value = 0.0;
	place = 0.1;
	while (is_digit(*str))
	{
		value += (*str - '0') * place;
		place *= 0.1;
		str++;
	}
	return (value);
}

double	ft_atod(const char *str)
{
	double	value;
	int		sign;

	value = 0.0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (is_digit(*str))
	{
		value = value * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		value += fraction_value(str + 1);
	return (value * sign);
}
