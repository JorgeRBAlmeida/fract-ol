/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:22:24 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/03 16:52:58 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

//z0 -> [0 + 0i]
//while ((z_r >= -2 && z_r <= 2) && (z_im >= -2 && z_im <= 2))

int	mandelbrot(double x, double y)
{
	int		limit;
	double	new_z_r;
	int		i;
	double	z_r;
	double	z_im;

	limit = 100;
	new_z_r = 0;
	i = 0;
	z_r = x;
	z_im = y;
	while(pow(z_r, 2) + pow(z_im, 2) <= 4 && i < limit)
	{
		new_z_r = pow(z_r, 2) - pow(z_im, 2) + x;
		z_im = 2 * z_r * z_im + y;	
		z_r = new_z_r;
		i++;
	}
	return (i);
}


int	julia_selector(double x, double y, char **argv)
{
	int	it;
	
	it = 0;
	if (!ft_strncmp(argv[2], "1", 1))
		it = julia(x, y, -0.4, 0.6);
	else if (!ft_strncmp(argv[2], "2", 1))
		it = julia(x, y, 0.285, 0);
	else if (!ft_strncmp(argv[2], "3", 1))
		it = julia(x, y, 0.285, 0.01);
	else if (!ft_strncmp(argv[2], "4", 1))
		it = julia(x, y, 0.45, 0.1428);
	else if (!ft_strncmp(argv[2], "5", 1))
		it = julia(x, y, -0.70176, -0.3842);
	else if (!ft_strncmp(argv[2], "6", 1))
		it = julia(x, y, -0.835, -0.2321);
	return (it);
}

int	julia(double x, double y, double c_r, double c_im)
{
	int		limit;
	double	new_z_r;
	double	z_r;
	double	z_im;
	int		i;

	limit = 100;
	new_z_r = 0;
	z_r = x;
	z_im = y;
	i = 0;
	while (pow(z_r, 2) + pow(z_im, 2) <= 4 && i < limit)
	{
		new_z_r = pow(z_r, 2) - pow(z_im, 2) + c_r;
		z_im = 2 * z_r * z_im + c_im;	
		z_r = new_z_r;
		i++;
	}
	return (i);
}
