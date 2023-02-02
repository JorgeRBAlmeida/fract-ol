/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:22:24 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/02 18:58:30 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

// int mandelbrot(int x, int y, t_data *data)
// {
// 	if (pow(x -  data->s_width/2, 2) + pow(y -  data->s_width/2, 2) <= pow(200, 2))
// 		return(1);
// 	else
// 		return(0);
// }

// int julia(int x, int y, t_data *data)
// {
// 	if (((x > 100 && x < 400 ) && (y > 100 && y < 400)) && data )
// 		return (1);
// 	else
// 		return (0);
// }


int mandelbrot(double x, double y, t_data *data)
{
	int limit = 1000;
	double new_z_r;
	int i = 0;
	double z_r = 0;
	double z_im = 0;

	//z0 -> [0 + 0i]
	//while ((z_r >= -2 && z_r <= 2) && (z_im >= -2 && z_im <= 2))
	while(pow(z_r, 2) + pow(z_im, 2) <= 4 && i < limit && data)
	{
		new_z_r = pow(z_r, 2) - pow(z_im, 2) + x;
		z_im = 2 * z_r * z_im + y;	
		z_r = new_z_r;

		i++;
	}
	return(i);
}


int julia(double x, double y, double c_r, double c_im, t_data *data)
{
	int limit = 1000;
	double new_z_r;
	double z_r = x;
	double z_im = y;
	int i = 0;

	//z0 -> [0 + 0i]
	//while ((z_r >= -2 && z_r <= 2) && (z_im >= -2 && z_im <= 2))
	while(pow(z_r, 2) + pow(z_im, 2) <= 4 && i < limit && data)
	{
		new_z_r = pow(z_r, 2) - pow(z_im, 2) + c_r;
		z_im = 2 * z_r * z_im + c_im;	
		z_r = new_z_r;

		i++;
	}
	return(i);
}
