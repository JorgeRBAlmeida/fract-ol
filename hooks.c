/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:46:31 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/04 17:24:06 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_event(int mouse_code, int x, int y, t_data *data)
{
	(void) x;
	(void) y;

	if (mouse_code == 5)
	{
		data->zoom *= 1.01;
		drawer(data);
	}
	else if (mouse_code == 4)
	{
		data->zoom *= 0.9;
		drawer(data);
	}
	return (0);
}

int	key_event(int mouse_code, int x, int y, t_data *data)
{
	(void) x;
	(void) y;

	if (mouse_code == 5)
	{
		data->zoom *= 1.1;
		drawer(data);
	}
	else if (mouse_code == 4)
	{
		data->zoom *= 0.9;
		drawer(data);
	}
	return (0);
}
