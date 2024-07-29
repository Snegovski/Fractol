/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-bakr <ral-bakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:17:44 by ral-bakr          #+#    #+#             */
/*   Updated: 2024/05/20 15:38:53 by ral-bakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	write(1, "wrong args\n", 12);
	write(1, "Mandelbrot -> ./fractol 1\n", 26);
	write(1, "Julia -> ./fractol -0.8 0.156\n", 30);
	exit(1);
}

int	ft_exit(void)
{
	exit (1);
	return (0);
}

static double	map(t_data *img, int x, int y)
{
	double	map;

	map = 0;
	if (x && !y)
		map = (x - (img->width >> 1)) / img->view;
	else if (!x && y)
		map = (y - (img->height >> 1)) / img->view;
	return (map);
}

void	init_m(t_data *img)
{
	double	x;
	double	y;

	img->iteration = 0;
	img->max_iteration = 100;
	img->trgb = 0;
	img->xtemp = 0.0;
	x = 0.0;
	y = 0.0;
	while (x * x + y * y <= 2 * 2 && img->iteration < img->max_iteration)
	{
		img->xtemp = x * x - y * y + img->m;
		y = 2 * x * y + img->m1;
		x = img->xtemp;
		img->iteration = img->iteration + 1;
	}
}

void	plot_mandel(t_data *img)
{
	int	i;
	int	j;

	i = 1;
	while (i < img->width)
	{
		img->m = map(img, i, 0);
		j = 1;
		while (j < img->height)
		{
			img->m1 = map(img, 0, j);
			init_m(img);
			img->trgb = img->base_color * (img->iteration
					/ (float)(img->max_iteration));
			my_mlx_pixel_put(img, i, j, img->trgb);
			j++;
		}
		i++;
	}
}
