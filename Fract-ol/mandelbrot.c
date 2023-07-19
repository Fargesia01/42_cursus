/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:32:12 by slott             #+#    #+#             */
/*   Updated: 2022/05/16 16:19:29 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fract_ol.h"

int	mandelbrot(double x, double y, t_mlx *inst)
{
	t_mandel	f;

	f = init_mandel(&f, x, y, inst);
	while (f.it < inst->max_it && f.zr * f.zr + f.zi * f.zi < 4)
	{
		f.tmp = f.zr;
		f.zr = f.zr * f.zr - f.zi * f.zi + f.cr;
		f.zi = 2 * f.tmp * f.zi + f.ci;
		f.it++;
	}
	if (f.it == inst->max_it)
		return (0x00000000);
	return (choice(f.it, inst));
}

int	julia(double x, double y, t_mlx *inst)
{
	t_mandel	f;

	f = init_julia(&f, x, y, inst);
	while (f.it < inst->max_it && f.zr * f.zr + f.zi * f.zi < 4)
	{
		f.tmp = f.zr;
		f.zr = f.zr * f.zr - f.zi * f.zi + f.cr;
		f.zi = 2 * f.tmp * f.zi + f.ci;
		f.it++;
	}
	if (f.it == inst->max_it)
		return (0x00000000);
	return (choice(f.it, inst));
}

t_mandel	init_julia(t_mandel *fract, double x, double y, t_mlx *inst)
{
	fract->zr = x / inst->zoom + inst->cx;
	fract->zi = y / inst->zoom + inst->cy;
	fract->cr = inst->jcr;
	fract->ci = inst->jci;
	fract->it = 0;
	fract->tmp = 0;
	return (*fract);
}

t_mandel	init_mandel(t_mandel *fract, double x, double y, t_mlx *inst)
{
	fract->zr = 0;
	fract->zi = 0;
	fract->cr = x / inst->zoom + inst->cx;
	fract->ci = y / inst->zoom + inst->cy;
	fract->it = 0;
	fract->tmp = 0;
	return (*fract);
}
