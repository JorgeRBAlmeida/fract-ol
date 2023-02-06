/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:40:06 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/06 19:36:43 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_setting(t_data *fract, char **argv)
{
	fract->mlx = mlx_init();
	fract->height = 700;
	fract->width = 700;
	fract->sizes.max = 2;
	fract->sizes.min = -2;
	fract->sizes.mx = 0;
	fract->sizes.my = 0;
	fract->sizes.zoom = 1;
	fract->argv = argv;
	fract->mlx_win = mlx_new_window(fract->mlx, fract->width, fract->height, \
									"Fract-ol");
	fract->img = mlx_new_image(fract->mlx, fract->width, fract->height);
	fract->addr = mlx_get_data_addr(fract->img, &fract->bits_per_pixel, \
								&fract->line_length, &fract->endian);
}

void	pixel_drawer(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	converter(int axis_point, int axis_win_size, t_data *data, double move)
{
	double	complex_size;
	double	min;
	double	max;
	double	zoom;

	zoom = data->sizes.zoom;
	min = data->sizes.min + move;
	max = data->sizes.max + move;
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
				it = mandelbrot(converter(x, data->width, data, \
		data->sizes.mx), converter(y, data->height, data, data->sizes.my));
			else if (ft_strncmp(data->argv[1], "julia", 5) == 0)
				it = julia_selector(converter(x, data->width, data, data->\
	sizes.mx), converter(y, data->height, data, data->sizes.my), data->argv);
			if (it == 100)
				pixel_drawer(data, x, 699 - y, 0x00110000);
			else
				pixel_drawer(data, x, 699 - y, 0x00032af2 * it);
			y ++;
		}
		x ++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
