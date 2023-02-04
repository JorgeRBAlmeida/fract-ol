/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:59:49 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/04 17:18:58 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <unistd.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		height;
	int		width;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	double	zoom;
	char	**argv;
}				t_data;

int		mandelbrot(double x, double y);
int		julia(double x, double y, double c_r, double c_im);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_argv2cmp(char **argv, const char *range);
int		julia_selector(double x, double y, char **argv);
void	invalid_arg_msger(void);
int	mouse_event(int mouse_code, int x, int y, t_data *data);
double	converter(int axis_point, int axis_win_size, double max, double zoom);
void	drawer(t_data *data);
double	my_pow(double num, int times);

#endif