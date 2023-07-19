/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:21:22 by slott             #+#    #+#             */
/*   Updated: 2022/05/03 19:42:28 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include <math.h>
# include <stdint.h>
# include <string.h>
# include <pthread.h>

typedef struct mlx_instance
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	char			*type;
	int				max_it;
	__int128		zoom;
	long double		cx;	
	long double		cy;
	int				trigger;
	long double		jcr;
	long double		jci;
	int				pal;
	pthread_mutex_t	mutex;
	int				**buddha_set;
	int				*id;
}	t_mlx;

typedef struct s_mandelbrot
{
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
	int		it;
	long double	tmp;
}	t_mandel;

int				mandelbrot(double x, double y, t_mlx *inst);
t_mandel		init_mandel(t_mandel *fract, double x, double y, t_mlx *inst);
void			my_pxl_put(t_mlx *data, int x, int y, int color);
void			draw_fractal(t_mlx *inst);
int				key_hook(int keycode, t_mlx *inst);
int				mouse_hook(int mousecode, int x, int y, t_mlx *inst);
char			*ft_cpy(char *src);
int				ft_strlen(char *str);
int				julia(double x, double y, t_mlx *inst);
t_mandel		init_julia(t_mandel *fract, double x, double y, t_mlx *inst);
int				burningship(double x, double y, t_mlx *inst);
int				gradient_un(int it);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				mmove(int x, int y, t_mlx *inst);
int				nb(int it, t_mlx *inst);
int				bn(int it, t_mlx *inst);
int				choice(int it, t_mlx *inst);
int				key_hook2(int keycode, t_mlx *inst);
void			*compute(void *ss);
void			launch_thread(t_mlx *inst);
int				buddha(double x, double y, t_mlx *inst);
void			draw_buddha(t_mlx *inst);

#endif
