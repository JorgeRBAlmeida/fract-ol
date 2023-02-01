/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:03:51 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/01 16:23:11 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double converter_x(int x, t_data *data)
{
	double x_min = -1;
	double x_max = 1;
	double complex_width = x_max - x_min;
	return (x_min + complex_width / data->s_width * x);
}

double converter_y(int y, t_data *data)
{
	double y_min = -1;
	double y_max = 1;
	double complex_height = y_max - y_min;;
	return (y_min + complex_height / data->s_height * y);
}

void	drawer(t_data *data)
{
	int	x;
	int	y;
	int	limit;

	limit = 0;
	x = 0 + limit;
	y = 0 + limit;

	while (x < data->s_width - limit)
	{
		y = 0 + limit;
		while (y < data->s_height - limit)
		{
			/* if ((x == limit || x == data->s_width - limit - 1) || (y == limit || y == data->s_height - limit - 1) ) */
			// int it = julia(converter_x(x, 4, data), converter_y(y, 4, data), 0.285, 0, data);
			int it = mandelbrot(converter_x(x, data), converter_y(y, data), data);
			if (it == 100)
				my_mlx_pixel_put(data, x, y, 0x00110000);
			else
				my_mlx_pixel_put(data, x, y, 0x00002200 * it);
			y ++;
		}
		x ++;
	}
	/* my_mlx_pixel_put(data, x, y, 0x0000FF00); */
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	main(void)
{
	t_data	fract;

	fract.s_height = 500;
	fract.s_width = 800;
	fract.mlx = mlx_init();
	fract.mlx_win = mlx_new_window(fract.mlx, fract.s_width, fract.s_height, 
								"Hello world!");
	fract.img = mlx_new_image(fract.mlx, fract.s_width, fract.s_height);
	fract.addr = mlx_get_data_addr(fract.img, &fract.bits_per_pixel, &fract.line_length,
								&fract.endian);
	drawer(&fract);
	
	mlx_loop(fract.mlx);
}
