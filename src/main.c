/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraksana <kraksana@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:30:00 by kraksana          #+#    #+#             */
/*   Updated: 2026/08/01 18:30:00 by kraksana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!parse_arguments(argc, argv, &fractal))
		return (EXIT_FAILURE);
	init_view(&fractal);
	if (!init_mlx(&fractal))
		return (EXIT_FAILURE);
	render_fractal(&fractal);
	setup_hooks(&fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
