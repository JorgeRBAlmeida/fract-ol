/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:46:31 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/06 19:32:34 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_event(int mouse_code, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (mouse_code == 5)
	{
		data->sizes.zoom = data->sizes.zoom * 1.1;
		drawer(data);
	}
	else if (mouse_code == 4)
	{
		data->sizes.zoom = data->sizes.zoom * 0.95;
		drawer(data);
	}
	return (0);
}

int	key_event(int key_code, t_data *data)
{
	if (key_code == ESC_KEY)
	{
		exit_program(data);
	}
	else if (key_code == ARROW_LEFT)
	{
		data->sizes.mx = data->sizes.mx - 0.5;
		drawer(data);
	}
	else if (key_code == ARROW_RIGHT)
	{
		data->sizes.mx = data->sizes.mx + 0.5;
		drawer(data);
	}
	else if (key_code == ARROW_DOWN)
	{
		data->sizes.my = data->sizes.my - 0.5;
		drawer(data);
	}
	else if (key_code == ARROW_UP)
	{
		data->sizes.my = data->sizes.my + 0.5;
		drawer(data);
	}
	return (0);
}

int	exit_program(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	data->mlx = NULL;
	exit(EXIT_SUCCESS);
}

void	invalid_arg_event(void)
{
	ft_putstr_fd("******** ATENÇÃO ********\nOs argumentos aceitos são:\n", 1);
	ft_putstr_fd("./fractol mandelbrot\n./fractol julia 1\n", 1);
	ft_putstr_fd("./fractol julia 2\n./fractol julia 3\n", 1);
	ft_putstr_fd("./fractol julia 4\n./fractol julia 5\n", 1);
	ft_putstr_fd("./fractol julia 6\n", 1);
}
