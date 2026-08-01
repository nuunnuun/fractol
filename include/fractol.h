/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraksana <kraksana@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:30:00 by kraksana          #+#    #+#             */
/*   Updated: 2026/08/01 18:30:00 by kraksana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <MLX42/MLX42.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 100
# define BLACK 0x000000FF
# define ZOOM_BASE 0.80

typedef enum e_set
{
	MANDELBROT,
	JULIA
} t_set;

typedef struct s_complex
{
	double	real;
	double	imag;
} t_complex;

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_set		set;
	double		min_real;
	double		max_real;
	double		min_imag;
	double		max_imag;
	double		julia_real;
	double		julia_imag;
	int			max_iterations;
	bool		needs_render;
} t_fractal;

int			parse_arguments(int argc, char **argv, t_fractal *fractal);
double		ft_atod(const char *str);
void		print_usage(void);
void		init_view(t_fractal *fractal);
int			init_mlx(t_fractal *fractal);
void		setup_hooks(t_fractal *fractal);
void		render_loop(void *param);
void		render_fractal(t_fractal *fractal);
int			fractal_iterations(t_fractal *fractal, t_complex point);
uint32_t	get_color(int iterations, int max_iterations);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);
void		ft_putstr_fd(const char *str, int fd);

#endif
