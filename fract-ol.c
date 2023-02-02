/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:03:51 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/02 19:58:51 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	pixel_drawer(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double win_converter(int axis_point, int axis_window_size)
{
	double min_size = -2;
	double max_size;
	double complex_size;
	
	min_size = -2;
	max_size = 2;
	complex_size = max_size - min_size;
	return (min_size + complex_size / axis_window_size * axis_point);
}

void	drawer(t_data *data, char **argv)
{
	int	x;
	int	y;
	int it;

	x = 0;
	while (x < data->s_width)
	{
		y = 0;
		while (y < data->s_height)
		{
			/* if ((x == limit || x == data->s_width - limit - 1) || (y == limit || y == data->s_height - limit - 1) ) */
			// int it = julia(window_converter(x, data->s_width), 
			 				//window_converter(y, data->s_height), 0.285, 0, data);
			if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
				it = mandelbrot(win_converter(x, data->s_width), win_converter(y, data->s_height), data);
			else if (ft_strncmp(argv[1], "julia", 5) == 0)
				it = julia(win_converter(x, data->s_width), 
			 				win_converter(y, data->s_height), -0.835, -0.2321, data);
			if (it == 1000)
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

	if (argc == 2)
	{
		fract.s_height = 1000;
		fract.s_width = 1000;
		fract.mlx = mlx_init();
		fract.mlx_win = mlx_new_window(fract.mlx, fract.s_width, fract.s_height, 
									"Fract-ol");
		fract.img = mlx_new_image(fract.mlx, fract.s_width, fract.s_height);
		fract.addr = mlx_get_data_addr(fract.img, &fract.bits_per_pixel, &fract.line_length,
									&fract.endian);
		drawer(&fract, argv);
		
		mlx_loop(fract.mlx);
	}
	else
		ft_putstr_fd("**Atenção**\nOs argumentos aceitos são:\n", 1);
		ft_putstr_fd("mandelbrot, julia\n", 1);
		ft_putstr_fd("se escolher julia deverá por mais um argumento de 1 até 6.\n", 1);
		ft_putstr_fd("ex:\n", 1);
		ft_putstr_fd("./fract-ol mandelbrot\n", 1);
		ft_putstr_fd("./fract-ol julia 3\n", 1);
		ft_putstr_fd("./fract-ol julia 5\n", 1);
}
