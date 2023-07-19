/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:20:49 by slott             #+#    #+#             */
/*   Updated: 2022/05/16 16:19:32 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fract_ol.h"

void	my_pxl_put(t_mlx *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractal(t_mlx *inst)
{
	double	i;
	double	j;

	i = 0;
	inst->buddha_set = malloc(1080 * sizeof(int *));
	for (int i = 0; i < 1080; i++)
	{
		inst->buddha_set[i] = malloc(1920 * sizeof(int));
	}
	inst->zoom *= 10;
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
		{
			buddha(j, i, inst);
			j++;
		}
		i++;
	}
	draw_buddha(inst);
}

int	main(int argc, char **argv)
{
	t_mlx	i;

	if (argc != 4)
	{
		printf("Nombre d'argument incorrect\n");
		return (1);
	}
	i.type = ft_cpy(argv[1]);
	if (ft_strcmp(i.type, "buddha") != 0)
	{
		i.cx = -3.8;
		i.cy = -2.5;
	}
	else
	{
		i.cx = -2.6;
		i.cy = -1.4;
	}
	i.zoom = 270;
	i.trigger = 0;
	i.max_it = ft_atoi(argv[2]);
	i.pal = ft_atoi(argv[3]);
	i.mlx_ptr = mlx_init();
	i.win_ptr = mlx_new_window(i.mlx_ptr, 1920, 1080, "Fract_ol");
	i.img = mlx_new_image(i.mlx_ptr, 1920, 1080);
	i.addr = mlx_get_data_addr(i.img, &i.bpp, &i.line_length, &i.endian);
	launch_thread(&i);
	mlx_key_hook(i.win_ptr, key_hook, &i);
	mlx_mouse_hook(i.win_ptr, mouse_hook, &i);
	mlx_hook(i.win_ptr, 6, 1 << 8, mmove, &i);
	mlx_loop(i.mlx_ptr);
	return (0);
}
