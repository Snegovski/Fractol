/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-bakr <ral-bakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:17:37 by ral-bakr          #+#    #+#             */
/*   Updated: 2024/05/29 13:22:51 by ral-bakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	mouse(int mouse_code, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	mlx_clear_window(img->mlx, img->mlx_win);
	if (mouse_code == 5)
		img->view *= 1.1;
	else if (mouse_code == 4)
		img->view /= 1.1;
	if (img->flag == 0)
		plot_julia(img);
	else if (img->flag == 1)
		plot_mandel(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	escape(int keycode, t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	if (img->flag == 0)
		plot_julia(img);
	else if (img->flag == 1)
		plot_mandel(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}
