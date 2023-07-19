/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:01:19 by slott             #+#    #+#             */
/*   Updated: 2022/04/15 17:24:31 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fract_ol.h"

int	gradient_un(int it)
{
	int	i;
	int	gra[16];

	i = it % 16;
	gra[0] = 0x00421E0F;
	gra[1] = 0x0019071A;
	gra[2] = 0x0009012F;
	gra[3] = 0x00040449;
	gra[4] = 0x00000764;
	gra[5] = 0x000C2C8A;
	gra[6] = 0x001852B1;
	gra[7] = 0x00397DD1;
	gra[8] = 0x0086B5E5;
	gra[9] = 0x00D3ECF8;
	gra[10] = 0x00F1E9BF;
	gra[11] = 0x00F8C95F;
	gra[12] = 0x00FFAA00;
	gra[13] = 0x00CC8000;
	gra[14] = 0x00995700;
	gra[15] = 0x006A3403;
	return (gra[i]);
}

int	nb(int it, t_mlx *inst)
{
	double	tmp;
	double	c;

	tmp = 255 / inst->max_it;
	c = tmp * it + (256 * tmp * it) + (65536 * tmp * it);
	return (c);
}

int	bn(int it, t_mlx *inst)
{
	double	tmp;
	double	c;

	it = abs(it - inst->max_it);
	tmp = 255 / inst->max_it;
	c = tmp * it + (256 * tmp * it) + (65536 * tmp * it);
	return (c);
}

int	choice(int it, t_mlx *inst)
{
	if (inst->pal == 1)
		return (gradient_un(it));
	else if (inst->pal == 2)
		return (nb(it, inst));
	else if (inst->pal == 3)
		return (bn(it, inst));
	return (0);
}
