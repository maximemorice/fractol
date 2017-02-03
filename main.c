/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:41:17 by mmorice           #+#    #+#             */
/*   Updated: 2017/01/28 05:37:54 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/mlx.h"
#include "fractol.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_make_julia(t_env *e)
{
	e->x = -1;
	while (++e->x < e->image_x)
	{
		e->y = -1;
		while (++e->y < e->image_y)
		{
			e->z_r = (double)e->x / e->zoom + e->x1;
			e->z_i = (double)e->y / e->zoom + e->y1;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			if (e->i == e->max)
				e->img_color = mlx_get_color_value(e->mlx, 0x0000ff);
			else
				e->img_color = mlx_get_color_value(e->mlx, e->i * 250 / e->max);
			put_pixel(e, e->x, e->y);
		}
	}
}

void	ft_make_ship(t_env *e)
{
	e->x = -1;
	while (++e->x < e->image_x)
	{
		e->y = -1;
		while (++e->y < e->image_y)
		{
			e->c_r = (double)e->x / e->zoom + e->x1;
			e->c_i = (double)e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->max)
			{
				e->tmp = e->z_r;
				e->z_r = absolue(e->z_r * e->z_r) - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * absolue(e->z_i * e->tmp) + e->c_i;
				e->i++;
			}
			if (e->i == e->max)
				e->img_color = mlx_get_color_value(e->mlx, 0x0000ff);
			else
				e->img_color = mlx_get_color_value(e->mlx, e->i * 250 / e->max);
			put_pixel(e, e->x, e->y);
		}
	}
}

void	ft_make_mandelbrot(t_env *e)
{
	e->x = -1;
	while (++e->x < e->image_x)
	{
		e->y = -1;
		while (++e->y < e->image_y)
		{
			e->c_r = (double)e->x / e->zoom + e->x1;
			e->c_i = (double)e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			if (e->i == e->max)
				e->img_color = mlx_get_color_value(e->mlx, 0x0000ff);
			else
				e->img_color = mlx_get_color_value(e->mlx, e->i * 250 / e->max);
			put_pixel(e, e->x, e->y);
		}
	}
}

void	ft_argc_tree(t_env *e, t_env *i, t_env *o, char **argv)
{
	if (e->fractal == 1 || i->fractal == 2 || o->fractal == 4)
	{
		if (ft_strcmp(argv[2], "ship") == 0)
		{
			ship(o);
			mlx_loop(o->mlx);
		}
		if (ft_strcmp(argv[2], "julia") == 0)
		{
			julia(e);
			mlx_loop(e->mlx);
		}
		if (ft_strcmp(argv[2], "mandelbrot") == 0)
		{
			mandelbrot(i);
			mlx_loop(i->mlx);
		}
	}
}

int		main(int argc, char **argv)
{
	t_env e;
	t_env i;
	t_env o;

	i.fractal = 0;
	o.fractal = 0;
	e.fractal = 0;
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "ship") == 0)
			ship(&o);
		if (ft_strcmp(argv[1], "julia") == 0)
			julia(&e);
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			mandelbrot(&i);
		if (argc == 3)
			ft_argc_tree(&e, &i, &o, argv);
		if (argc == 2)
			ft_argc_two(&e, &i, &o);
	}
	ft_usage();
	return (0);
}
