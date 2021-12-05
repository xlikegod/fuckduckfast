/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorefor <amorefor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:25:09 by amorefor          #+#    #+#             */
/*   Updated: 2021/12/05 17:56:10 by amorefor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color(int z, int z1)
{
	if (z > 0 || z1 > 0)
		return (0x006400);
	else
		return (0xffffff);
}

float	max_numbs(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.523599);
	*y = (*x + *y) * sin(0.523599) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z[(int)y][(int)x];
	z1 = data->z[(int)y1][(int)x1];
// zoom
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
// color
	data->color = color(z, z1);
// 3d
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
// shift
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max = max_numbs(mod(x_step), mod(y_step));
	x_step = x_step / max;
	y_step = y_step / max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x = x + x_step;
		y = y + y_step;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			if (x < data->x - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->y - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
