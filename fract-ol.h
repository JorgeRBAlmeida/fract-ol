/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:59:49 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/01 16:12:59 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		s_height;
	int		s_width;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_data;

int mandelbrot(double x, double y, t_data *data);
int julia(double x, double y, double c_r, double c_im, t_data *data);

#endif