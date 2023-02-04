/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:03:51 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/04 17:31:14 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_drawer(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	converter(int axis_point, int axis_win_size, double max, double zoom)
{
	double	complex_size;
	double min;

	if (max > 0)
		min = - max;
	else
		min = 2 * max;
	complex_size = max - min;
	return (zoom * (min + complex_size / axis_win_size * axis_point));
}

void	drawer(t_data *data)
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
			if (ft_strncmp(data->argv[1], "mandelbrot", 10) == 0)
				it = mandelbrot(converter(x, data->width, 2, data->zoom), \
								converter(y, data->height, 2, data->zoom));
			else if (ft_strncmp(data->argv[1], "julia", 5) == 0)
				it = julia_selector(converter(x, data->width, 2, data->zoom), \
							converter(y, data->height, 2, data->zoom), data->argv);
			if (it == 100)
				pixel_drawer(data, x, 999 - y, 0x00110000);
			else
				pixel_drawer(data, x, 999 - y, 0x00032af2 * it);
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
		fract.mlx = mlx_init();
		fract.height = 1000;
		fract.width = 1000;
		fract.zoom = 1;
		fract.argv = argv;
		fract.mlx_win = mlx_new_window(fract.mlx, fract.width, fract.height, \
										"Fract-ol");
		fract.img = mlx_new_image(fract.mlx, fract.width, fract.height);
		fract.addr = mlx_get_data_addr(fract.img, &fract.bits_per_pixel, \
										&fract.line_length, &fract.endian);
		drawer(&fract);
		mlx_mouse_hook(fract.mlx_win, mouse_event, &fract);
		mlx_loop(fract.mlx);
	}
	else
		invalid_arg_msger();
}
