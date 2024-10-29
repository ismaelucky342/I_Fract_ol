/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:23:42 by ismherna          #+#    #+#             */
/*   Updated: 2024/10/29 23:56:11 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	box_fold(double v)
{
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

int	calc_bright_mandelbox(t_complex *z, t_complex *c, t_data *d)
{
	int		i;
	double	scale = 2.0;         
	double	fixed_radius = 1.0;  

	i = 0;
	while (i < d->iter)
	{
		z->r = box_fold(z->r);
		z->i = box_fold(z->i);

		double mag = sqrt(z->r * z->r + z->i * z->i);
		double factor = ball_fold(fixed_radius, mag);
		z->r = scale * z->r * factor + c->r;
		z->i = scale * z->i * factor + c->i;

		if (mag > fixed_radius * 2)
			break;
		i++;
	}
	return (map(calculate_ratio(i, 0, d->iter), 0, d->color[d->color_i]));
}

void	draw_mandelbox(t_data *data, int x, int y)
{
	t_complex	z;
	t_complex	c;

	z.r = 0;
	z.i = 0;
	c.r = map(calculate_ratio(x, 0, WIDTH), data->pos.x - data->pos.zoom,
			data->pos.x + data->pos.zoom);
	c.i = map(calculate_ratio(y, 0, HEIGHT), data->pos.y - data->pos.zoom,
			data->pos.y + data->pos.zoom);
	ft_put_pixel(data->img, x, y, calc_bright_mandelbox(&z, &c, data));
}

