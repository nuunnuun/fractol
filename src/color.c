/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraksana <kraksana@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:30:00 by kraksana          #+#    #+#             */
/*   Updated: 2026/08/01 18:30:00 by kraksana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	rgba(int red, int green, int blue, int alpha)
{
	return (((uint32_t)red << 24) | ((uint32_t)green << 16)
		| ((uint32_t)blue << 8) | (uint32_t)alpha);
}

uint32_t	get_color(int iterations, int max_iterations)
{
	int	red;
	int	green;
	int	blue;

	if (iterations == max_iterations)
		return (BLACK);
	red = iterations * 9 % 256;
	green = iterations * 5 % 256;
	blue = iterations * 13 % 256;
	return (rgba(red, green, blue, 255));
}
