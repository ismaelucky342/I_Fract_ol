/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:32:41 by ismherna          #+#    #+#             */
/*   Updated: 2024/10/29 20:33:01 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	calculate_ratio(double y, double a1, double a2)
{
	return ((y - a1) / (a2 - a1));
}

double	map(double ratio, double b1, double b2)
{
	return (b1 + ratio * (b2 - b1));
}

int	calc_bright(t_complex *z, t_complex *c, t_data *d)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < d->iter)
	{
		if ((z->r * z->r + z->i * z->i) > 4)
			break ;
		tmp = 2 * (z->r) * (z->i) + c->i;
		z->r = (z->r * z->r - z->i * z->i) + c->r;
		z->i = tmp;
		i++;
	}
	return (map(calculate_ratio(i, 0, d->iter), 0, d->color[d->color_i]));
}

void	draw_mandelbrot(t_data *data, int x, int y)
{
	t_complex	z;
	t_complex	c;

	z.r = 0;
	z.i = 0;
	c.r = map(calculate_ratio(x, 0, WIDTH), data->pos.x - data->pos.zoom,
			data->pos.x + data->pos.zoom);
	c.i = map(calculate_ratio(y, 0, HEIGHT), data->pos.y - data->pos.zoom,
			data->pos.y + data->pos.zoom);
	ft_put_pixel(data->img, x, y, calc_bright(&z, &c, data));
}
