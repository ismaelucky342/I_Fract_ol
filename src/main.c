/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:32:28 by ismherna          #+#    #+#             */
/*   Updated: 2024/10/29 23:52:33 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>
#include <X11/keysym.h>

int	input_validator(void)
{
	char	*entrada;
	int		ret;

	ft_printf("Selecciona el fractal: \n1.Mandelbrot\n2.Julia\n3.Burning_ship\n4.Mandelbox\n");
	ret = 0;
	while (ret == 0)
	{
		entrada = get_next_line(1);
		if (!entrada)
			return (1);
		if ((*entrada < '1' || *entrada > '5') || entrada[1] != '\n')
			ft_printf("Entrada no válida, introduce una opción del 1 al 3\n");
		else
			ret = *entrada - '0';
		free(entrada);
	}
	return (ret);
}

void	main_menu(t_data *data)
{
	int	input;

	data->color_i = 0;
	input = input_validator();
	data->color[0] = 0x00FF00;
	data->color[1] = 67080;
	data->color[2] = 0xFF0000;
	data->color[3] = 0xFFFFFFFF;
	data->iter = 50;
	data->pos.zoom = 1;

	if (input == 1)  // Mandelbrot
	{
		data->pos.x = -0.735;
		data->pos.zoom = 1.35;
		data->func = draw_mandelbrot;
	}
	else if (input == 2)  // Julia
	{
		data->pos.zoom = 1.5;
		data->func = draw_julia;
	}
	else if (input == 3)  // Burning Ship
	{
		data->pos.x = -1.8;
		data->pos.y = -0.08;
		data->pos.zoom = 1.8;
		data->func = draw_burning_ship;
	}
	else if (input == 4)  // Mandelbox
	{
		data->pos.x = 0.0;
		data->pos.y = 0.0;
		data->pos.zoom = 2.0;
		data->func = draw_mandelbox;
	}
}



int	main(void)
{
	t_data	*dat;

	dat = (t_data *)malloc(sizeof(t_data));
	if (dat == NULL)
		return (1);
	main_menu(dat);
	dat->mlx_ptr = mlx_init();
	if (dat->mlx_ptr == NULL)
		return (1);
	dat->win_ptr = mlx_new_window(dat->mlx_ptr, WIDTH, HEIGHT, "I_Fractol");
	if (dat->win_ptr == NULL)
		return (1);
	dat->img.img = mlx_new_image(dat->mlx_ptr, WIDTH, HEIGHT);
	dat->img.pix = mlx_get_data_addr(dat->img.img, &dat->img.bpp,
			&dat->img.line_len, &dat->img.endian);
	iterate_screen(dat);
	mlx_hook(dat->win_ptr, KeyRelease, KeyReleaseMask, on_keypress, dat);
	mlx_mouse_hook(dat->win_ptr, mouse_hook, dat);
	mlx_hook(dat->win_ptr, DestroyNotify, NoEventMask, close_on_escape, dat);
	mlx_loop(dat->mlx_ptr);
	mlx_destroy_image(dat->mlx_ptr, dat->img.img);
	mlx_destroy_window(dat->mlx_ptr, dat->win_ptr);
	mlx_destroy_display(dat->mlx_ptr);
	free(dat);
	return (0);
}