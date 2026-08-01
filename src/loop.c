/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraksana <kraksana@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:30:00 by kraksana          #+#    #+#             */
/*   Updated: 2026/08/01 18:30:00 by kraksana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_loop(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (!fractal->needs_render)
		return ;
	render_fractal(fractal);
	fractal->needs_render = false;
}
