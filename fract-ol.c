/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:03:51 by joalmeid          #+#    #+#             */
/*   Updated: 2023/01/31 19:04:00 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	drawer(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 500)
	{
		y = 0;
		while (y < 500)
		{
			if (x < y)
				my_mlx_pixel_put(data, x, y, 0x00FF0000);
			else
				my_mlx_pixel_put(data, x, y, 0x0000FF00);
			y ++;
		}
		x ++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	main(void)
{
	t_data	fract;

	fract.mlx = mlx_init();
	fract.mlx_win = mlx_new_window(fract.mlx, 500, 500, "Hello world!");
	fract.img = mlx_new_image(fract.mlx, 500, 500);
	fract.addr = mlx_get_data_addr(fract.img, &fract.bits_per_pixel, &fract.line_length,
								&fract.endian);
	drawer(&fract);
	
	mlx_loop(fract.mlx);
}
