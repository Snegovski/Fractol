/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-bakr <ral-bakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:17:30 by ral-bakr          #+#    #+#             */
/*   Updated: 2024/05/29 13:23:42 by ral-bakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "./mlx/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
	int		base_color;
	int		trgb;
	int		max_iter;
	int		iteration;
	int		max_iteration;
	double	view;
	double	jx;
	double	jy;
	int		flag;
	double	zoom;
	double	m;
	double	m1;
	double	xtemp;
	double	temp1;
	double	temp2;

}				t_data;

void	plot_fractol(t_data *img);
void	plot_julia(t_data *img);
void	plot_mandel(t_data *img);
int		escape(int keycode, t_data *img);
int		mouse(int mouse_code, int x, int y, t_data *img);
void	ft_error(void);
int		ft_exit(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
double	ft_atof(char *str, t_data *img);

#endif
