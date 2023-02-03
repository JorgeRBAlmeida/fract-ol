/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:03:51 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/03 17:05:55 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	pixel_drawer(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	win_converter(int axis_point, int axis_window_size)
{
	double	min_size;
	double	max_size;
	double	complex_size;

	min_size = -2;
	max_size = 2;
	complex_size = max_size - min_size;
	return (min_size + complex_size / axis_window_size * axis_point);
}

void	drawer(t_data *data, char **argv)
{
	int	x;
	int	y;
	int	it;

	x = 0;
	while (x < data->width)
	{
		y = 0;
		while (y < data->height)
		{
			if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
				it = mandelbrot(win_converter(x, data->width), \
								win_converter(y, data->height));
			else if (ft_strncmp(argv[1], "julia", 5) == 0)
				it = julia_selector(win_converter(x, data->width), \
									win_converter(y, data->height), argv);
			if (it == 100)
				pixel_drawer(data, x, (data->height - 1) - y, 0x00110000);
			else
				pixel_drawer(data, x, (data->height - 1) - y, 0x00032af2 * it);
			y ++;
		}
		x ++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	fract;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || \
		(argc == 3 && !ft_strncmp(argv[1], "julia", 5) && \
			!ft_argv2cmp(argv, "123456")))
	{
		fract.height = 1000;
		fract.width = 1000;
		fract.mlx = mlx_init();
		fract.mlx_win = mlx_new_window(fract.mlx, fract.width, fract.height, \
										"Fract-ol");
		fract.img = mlx_new_image(fract.mlx, fract.width, fract.height);
		fract.addr = mlx_get_data_addr(fract.img, &fract.bits_per_pixel, \
										&fract.line_length, &fract.endian);
		drawer(&fract, argv);
		mlx_loop(fract.mlx);
	}
	else
	{
		ft_putstr_fd("** ATENÇÃO **\nOs argumentos aceitos são:\n", 1);
		ft_putstr_fd("mandelbrot, julia\n", 1);
		ft_putstr_fd("Escolhendo julia ponha mais um argumento de 1 a 6.\n", 1);
		ft_putstr_fd("ex:\n./fract-ol mandelbrot\n./fract-ol julia 3\n", 1);
		ft_putstr_fd("./fract-ol julia 5\n", 1);
	}
}
