/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:33:15 by ismherna          #+#    #+#             */
/*   Updated: 2024/10/30 00:14:41 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

void	*thread_function(void *arg)
{
	t_thread_data	*thread_data;
	t_data			*data;
	int				x;
	int				y;

	thread_data = (t_thread_data *)arg;
	data = thread_data->data;
	x = 0;
	while (x < WIDTH)
	{
		y = thread_data->start_y;
		while (y < thread_data->end_y)
		{
			data->func(data, x, y);
			y++;
		}
		x++;
	}
	return (NULL);
}

void	iterate_screen(t_data *d)
{
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_data[NUM_THREADS];
	int				i;
	int				lines_per_thread;

	lines_per_thread = HEIGHT / NUM_THREADS;
	i = 0;
	while (i < NUM_THREADS)
	{
		thread_data[i].data = d;
		thread_data[i].start_y = i * lines_per_thread;
		thread_data[i].end_y = (i == NUM_THREADS - 1) ? HEIGHT : (i + 1)
			* lines_per_thread;
		pthread_create(&threads[i], NULL, thread_function, &thread_data[i]);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img, 0, 0);
}

void	ft_put_pixel(t_img img, int x, int y, int color)
{
	int	offset;

	offset = (y * img.line_len) + (x * (img.bpp / 8));
	*(unsigned *)(img.pix + offset) = color;
}

/*
//------------------------VERSION BAJO RENDIMIENTO------------------------

void	iterate_screen(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			d->func(d, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img, 0, 0);
}

void	ft_put_pixel(t_img img, int x, int y, int color)
{
	int	offset;

	offset = (y * img.line_len) + (x * (img.bpp / 8));
	*(unsigned *)(img.pix + offset) = color;
}
*/