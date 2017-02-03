/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 05:38:58 by mmorice           #+#    #+#             */
/*   Updated: 2017/01/28 05:40:02 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libmlx/mlx.h"
#include <stdlib.h>

int		fct_close(int keycode, t_env *e)
{
	if (keycode == 124)
	{
		e->x1 = e->x1 - 0.1;
		e->x2 = e->x2 - 0.1;
	}
	if (keycode == 123)
	{
		e->x1 = e->x1 + 0.1;
		e->x2 = e->x2 + 0.1;
	}
	if (keycode == 126)
	{
		e->y1 = e->y1 + 0.1;
		e->y2 = e->y2 + 0.1;
	}
	if (keycode == 125)
	{
		e->y1 = e->y1 - 0.1;
		e->y2 = e->y2 - 0.1;
	}
	if (keycode == 69)
		e->zoom = e->zoom + 100;
	if (keycode == 53)
		exit(1);
	return (0);
}
