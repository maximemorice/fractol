/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 03:28:52 by mmorice           #+#    #+#             */
/*   Updated: 2017/01/28 05:40:43 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libmlx/mlx.h"
#include <stdlib.h>

float	absolue(float i)
{
	i = (i < 0 ? -i : i);
	return (i);
}

void	ft_argc_two(t_env *e, t_env *i, t_env *o)
{
	if (o->fractal == 4)
		mlx_loop(o->mlx);
	if (i->fractal == 2)
		mlx_loop(i->mlx);
	if (e->fractal == 1)
		mlx_loop(e->mlx);
}

void	ft_usage(void)
{
	ft_putendl("usage: ./fractol julia\nusage: ./fractol mandelbrot");
	ft_putendl("usage: ./fractol ship");
}

int		mouse_zoom(int bouton, int x, int y, t_env *e)
{
	x -= 1000 / 2;
	y -= 1000 / 2;
	if (bouton == 4)
	{
		e->zoom *= 1.1;
		e->x1 += x / e->zoom / 2.51 / 1000;
		e->y1 -= y / e->zoom / 2.51 / 1000;
	}
	if (bouton == 5)
		e->zoom /= 1.1;
	return (0);
}

int		mouse_mouv(int x, int y, t_env *e)
{
	x -= 1000 / 2;
	y -= 1000 / 2;
	e->c_r = ((float)x / 1000) * 2;
	e->c_i = ((float)y / 1000) * 2;
	return (0);
}
