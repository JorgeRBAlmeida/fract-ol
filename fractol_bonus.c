/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:03:51 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/06 17:16:20 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	fract;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11)) || \
		(argc == 3 && !ft_strncmp(argv[1], "julia", 6) && \
			!ft_argv2cmp(argv, "123456")))
	{
		init_setting(&fract, argv);
		drawer(&fract);
		mlx_mouse_hook(fract.mlx_win, mouse_event, &fract);
		mlx_key_hook(fract.mlx_win, key_event, &fract);
		mlx_hook(fract.mlx_win, 17, 0, exit_program, &fract);
		mlx_loop(fract.mlx);
	}
	else
		invalid_arg_event();
}
