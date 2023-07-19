/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:05:45 by slott             #+#    #+#             */
/*   Updated: 2022/05/03 19:42:31 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fract_ol.h"

void	*compute(void *ss)
{
	t_mlx	*inst;
	int		id;
	int i = 0;

	id = 0;
	inst = (t_mlx *)ss;
	pthread_mutex_lock(&inst->mutex);
	while (inst->id[i] != 0)
		i++;
	id = i;
	inst->id[i]++;
	pthread_mutex_unlock(&inst->mutex);
	//printf("ID : %d\n", id);
	for (int i = 0; i < 1920; i++)
	{
		for (int tmp = id; tmp < 1080; tmp += 30)
		{
			if (ft_strcmp(inst->type, "mandelbrot") == 0)
				my_pxl_put(inst, i, tmp, mandelbrot(i, tmp, inst));
			else if (ft_strcmp(inst->type, "julia") == 0)
				my_pxl_put(inst, i, tmp, julia(i, tmp, inst));
			else if (ft_strcmp(inst->type, "burningship") == 0)
				my_pxl_put(inst, i, tmp, burningship(i, tmp, inst));
			else if (ft_strcmp(inst->type, "buddha") == 0)
				buddha(i, tmp, inst);
		}
	}
	return (NULL);
}

void	launch_thread(t_mlx *inst)
{
	pthread_t	*thread;

	thread = malloc(30 * sizeof(pthread_t));
	if (!thread)
		return ;
	inst->id = malloc(30 * sizeof(int));
	if (!inst->id)
		return ;
	for (int i = 0; i < 30; i++)
	{
		inst->id[i] = 0;
	}
	if (ft_strcmp(inst->type, "buddha") == 0)
	{
		inst->zoom *= 1.5;
		inst->buddha_set = malloc(1080 * sizeof(int *));
		for (int i = 0; i < 1080; i++)
		{
			inst->buddha_set[i] = malloc(1920 * sizeof(int));
		}
	}
	for (int i = 0; i < 30; i++)
	{
		pthread_create(&thread[i], NULL, &compute, inst);
		usleep(700);
	}
	for (int i = 0; i < 30; i++)
	{
		pthread_join(thread[i], NULL);
	}
	if (ft_strcmp(inst->type, "buddha") == 0)
		draw_buddha(inst);
	else
		mlx_put_image_to_window(inst->mlx_ptr, inst->win_ptr, inst->img, 0, 0);
}
