/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:59:49 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/06 18:35:18 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

# define ESC_KEY 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

typedef struct s_sizes {
	double	min;
	double	max;
	double	mx;
	double	my;
	double	zoom;
}				t_sizes;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		height;
	int		width;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	t_sizes	sizes;
	char	**argv;
}				t_data;

int		mandelbrot(double x, double y);
int		julia(double x, double y, double c_r, double c_im);
int		julia_selector(double x, double y, char **argv);
double	my_pow(double num, int times);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_argv2cmp(char **argv, const char *range);
void	invalid_arg_event(void);
int		mouse_event(int mouse_code, int x, int y, t_data *data);
int		key_event(int key_code, t_data *data);
int		exit_program(t_data *data);
void	init_setting(t_data *fract, char **argv);
void	pixel_drawer(t_data *data, int x, int y, int color);
double	converter(int axis_point, int axis_win_size, t_data *data, double move);
void	drawer(t_data *data);

#endif