/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:21:49 by ismherna          #+#    #+#             */
/*   Updated: 2024/10/29 23:22:45 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	calc_bright_burning_ship(t_complex *z, t_complex *c, t_data *d)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < d->iter)
	{
		if ((z->r * z->r + z->i * z->i) > 4)
			break ;
		tmp = 2 * fabs(z->r * z->i) + c->i;
		z->r = (z->r * z->r - z->i * z->i) + c->r;
		z->i = tmp;
		i++;
	}
	return (map(calculate_ratio(i, 0, d->iter), 0, d->color[d->color_i]));
}

void	draw_burning_ship(t_data *data, int x, int y)
{
	t_complex	z;
	t_complex	c;

	z.r = 0;
	z.i = 0;
	c.r = map(calculate_ratio(x, 0, WIDTH), data->pos.x - data->pos.zoom,
			data->pos.x + data->pos.zoom);
	c.i = map(calculate_ratio(y, 0, HEIGHT), data->pos.y - data->pos.zoom,
			data->pos.y + data->pos.zoom);
	ft_put_pixel(data->img, x, y, calc_bright_burning_ship(&z, &c, data));
}
