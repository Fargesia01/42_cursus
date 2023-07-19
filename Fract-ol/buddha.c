/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddha.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:49:44 by slott             #+#    #+#             */
/*   Updated: 2022/05/03 19:21:50 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fract_ol.h"

int	buddha(double x, double y, t_mlx *inst)
{
	t_mandel	f;
	int tmp_zr;
	int tmp_zi;

	if (mandelbrot(x, y, inst) == 0)
		return (0);
	f = init_mandel(&f, x, y, inst);
	while (f.it < inst->max_it && f.zr * f.zr + f.zi * f.zi < 4)
	{
		tmp_zr = (f.zr - inst->cx) * inst->zoom;
		tmp_zi = (f.zi - inst->cy) * inst->zoom;	
		if (tmp_zr < 1920 && tmp_zr > 0 && tmp_zi < 1080 && tmp_zi > 0)
			inst->buddha_set[tmp_zi][tmp_zr]++;
		f.tmp = f.zr;
		f.zr = f.zr * f.zr - f.zi * f.zi + f.cr;
		f.zi = 2 * f.tmp * f.zi + f.ci;
		f.it++;
	}
	return (0);
}

void	draw_buddha(t_mlx *inst)
{
	double c;
	double it;
	double r, g, b;

	for (int i = 0; i < 1080; i++)
	{
		for (int j = 0; j < 1920; j++)
		{
			it = inst->buddha_set[i][j];
			if (it < 25)
			{
				b = it * (255 / 25);
				g = it * (255 / 55);
				r = it * (255 / 75);
			}
			else if (it > 25 && it < 55)
			{
				b = 255 - (it * (255 / 55));
				g = it * (255 / 55);
				r = it * (255 / 75);
			}
			else
			{
				g = 255 - (it * (255 / 75));
				r = it * (255 / 75);
				b = 255 - (it * (255 / 25));
			}
			c = (int)b + ((int)g * 256) + ((int)r * 65536);
			my_pxl_put(inst, j, i, c);
		}
	}
	mlx_put_image_to_window(inst->mlx_ptr, inst->win_ptr, inst->img, 0, 0);
}
