/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:22 by slott             #+#    #+#             */
/*   Updated: 2022/04/10 19:09:20 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fract_ol.h"

int	burningship(double x, double y, t_mlx *inst)
{
	t_mandel	f;

	f = init_mandel(&f, x, y, inst);
	while (f.it < inst->max_it && f.zr * f.zr + f.zi * f.zi < 4)
	{
		f.tmp = f.zr;
		f.zr = f.zr * f.zr - f.zi * f.zi + f.cr;
		f.zi = fabsl(2 * f.tmp * f.zi) + f.ci;
		f.it++;
	}
	if (f.it == inst->max_it)
		return (0x00000000);
	return (choice(f.it, inst));
}
