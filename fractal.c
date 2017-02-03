/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 01:54:34 by mmorice           #+#    #+#             */
/*   Updated: 2017/01/28 05:26:52 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libmlx/mlx.h"

void	put_pixel(t_env *e, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (x > 0 && y > 0 && x < 1000 && y < 1000)
	{
		r = ((e->img_color & 0xFF0000) >> 16);
		g = ((e->img_color & 0xFF00) >> 8);
		b = ((e->img_color & 0xFF));
		e->data[y * e->s_line + x * e->bpp / 8] = b;
		e->data[y * e->s_line + x * e->bpp / 8 + 1] = g;
		e->data[y * e->s_line + x * e->bpp / 8 + 2] = r;
	}
}

int		loop_hook(t_env *e)
{
	e->imag = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->imag, &e->bpp, &e->s_line, &e->endian);
	e->img_color = mlx_get_color_value(e->mlx, 0x000033);
	if (e->fractal == 2)
		ft_make_mandelbrot(e);
	else if (e->fractal == 4)
		ft_make_ship(e);
	else
		ft_make_julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->imag, 0, 0);
	mlx_destroy_image(e->mlx, e->imag);
	return (0);
}

void	julia(t_env *e)
{
	e->fractal = 1;
	e->max = 50;
	e->image_y = 1000;
	e->image_x = 1000;
	e->x1 = -2.7;
	e->x2 = 0.3;
	e->y1 = -2.5;
	e->y2 = 0.5;
	e->zoom = 185;
	e->c_r = 0.285;
	e->c_i = 0.01;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "julia");
	mlx_hook(e->win, 6, (1l << 6), mouse_mouv, e);
	mlx_hook(e->win, 4, (1l << 2), mouse_zoom, e);
	mlx_key_hook(e->win, fct_close, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
}

void	ship(t_env *i)
{
	i->fractal = 4;
	i->max = 50;
	i->image_y = 1000;
	i->image_x = 1000;
	i->x1 = -2.1;
	i->x2 = 0.6;
	i->y1 = -1.2;
	i->y2 = 1.2;
	i->zoom = 385;
	i->mlx = mlx_init();
	i->win = mlx_new_window(i->mlx, 1000, 1000, "burning ship");
	mlx_hook(i->win, 4, (1l << 2), mouse_zoom, i);
	mlx_key_hook(i->win, fct_close, i);
	mlx_loop_hook(i->mlx, loop_hook, i);
}

void	mandelbrot(t_env *i)
{
	i->fractal = 2;
	i->max = 50;
	i->image_y = 1000;
	i->image_x = 1000;
	i->x1 = -2.1;
	i->x2 = 0.6;
	i->y1 = -1.2;
	i->y2 = 1.2;
	i->zoom = 385;
	i->mlx = mlx_init();
	i->win = mlx_new_window(i->mlx, 1000, 1000, "mandelbrot");
	mlx_hook(i->win, 4, (1l << 2), mouse_zoom, i);
	mlx_key_hook(i->win, fct_close, i);
	mlx_loop_hook(i->mlx, loop_hook, i);
}
