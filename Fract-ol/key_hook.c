/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:50:54 by slott             #+#    #+#             */
/*   Updated: 2022/05/16 15:21:48 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fract_ol.h"

int	key_hook(int keycode, t_mlx *inst)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 37)
	{	
		if (inst->trigger == 1)
			inst->trigger = 0;
		else
			inst->trigger = 1;
		return (1);
	}
	if (keycode == 8)
	{
		inst->pal++;
		if (inst->pal > 3)
			inst->pal = 1;
		launch_thread(inst);
		return (0);
	}
	return (key_hook2(keycode, inst));
}

int	key_hook2(int keycode, t_mlx *inst)
{
	if (keycode > 122 && keycode < 127)
	{
		if (keycode == 123)
			inst->cx -= 0.5 / (inst->zoom / 300);
		else if (keycode == 124)
			inst->cx += 0.5 / (inst->zoom / 300);
		else if (keycode == 125)
			inst->cy += 0.5 / (inst->zoom / 300);
		else if (keycode == 126)
			inst->cy -= 0.5 / (inst->zoom / 300);
	}
	else if (keycode == 78)
		inst->max_it -= 200;
	else if (keycode == 69)
		inst->max_it += 200;
	launch_thread(inst);
	return (1);
}

int	mouse_hook(int mousecode, int x, int y, t_mlx *inst)
{
	if (mousecode == 5 || mousecode == 1)
	{
		inst->cx = ((double)x / inst->zoom + inst->cx) - ((double)x / (inst->zoom * 1.5));
		inst->cy = ((double)y / inst->zoom + inst->cy) - ((double)y / (inst->zoom * 1.5));
		inst->zoom *= 1.5;
	}
	else if (mousecode == 4 || mousecode == 2)
	{
		inst->cx = ((double)x / inst->zoom + inst->cx) - ((double)x / (inst->zoom / 1.3));
		inst->cy = ((double)y / inst->zoom + inst->cy) - ((double)y / (inst->zoom / 1.3));
		inst->zoom /= 1.3;
	}
	//printf("%lld\n", inst->zoom);
	launch_thread(inst);
	return (1);
}

int	mmove(int x, int y, t_mlx *inst)
{
	if (ft_strcmp(inst->type, "julia") == 0 && inst->trigger == 1)
	{
		inst->jcr = (double)x / 640 - 1.5;
		inst->jci = (double)y / 360 - 1.5;
		launch_thread(inst);
	}
	return (0);
}
