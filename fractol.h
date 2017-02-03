/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:34:07 by mmorice           #+#    #+#             */
/*   Updated: 2017/01/28 05:27:13 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./libft/libft.h"

typedef struct		s_axe
{
	int				dx;
	int				dy;
}					t_axe;

typedef struct		s_env
{
	unsigned int	img_color;
	void			*mlx;
	void			*win;
	void			*imag;
	int				bpp;
	int				s_line;
	char			*data;
	int				endian;
	int				zoom;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	int				max;
	int				image_x;
	int				image_y;
	int				x;
	int				y;
	float			c_r;
	float			c_i;
	float			tmp;
	float			z_i;
	float			z_r;
	int				i;
	float			xx;
	float			yy;
	int				fractal;
}					t_env;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

float				absolue(float i);
void				ft_argc_two(t_env *e, t_env *i, t_env *o);
void				put_pixel(t_env *e, int x, int y);
void				ft_usage(void);
int					loop_hook(t_env *e);
int					mouse_mouv(int x, int y, t_env *e);
int					mouse_zoom(int bouton, int x, int y, t_env *e);
int					fct_close(int keycode, t_env *e);
void				julia(t_env *e);
void				ship(t_env *e);
void				mandelbrot(t_env *e);
void				ft_make_mandelbrot(t_env *e);
void				ft_make_julia(t_env *e);
void				ft_make_ship(t_env *e);
#endif
