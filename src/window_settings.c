/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apollo <apollo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:33:50 by ismherna          #+#    #+#             */
/*   Updated: 2024/11/15 18:14:31 by apollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_on_escape(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		close_on_escape(data);
	else if (keysym == 'w' || keysym == 65362)
		data->pos.y -= data->pos.zoom * 0.2;
	else if (keysym == 's' || keysym == 65364)
		data->pos.y += data->pos.zoom * 0.2;
	else if (keysym == 'a' || keysym == 65361)
		data->pos.x -= data->pos.zoom * 0.2;
	else if (keysym == 'd' || keysym == 65363)
		data->pos.x += data->pos.zoom * 0.2;
	else if (keysym == '+')
		data->pos.zoom *= 0.7;
	else if (keysym == '-')
		data->pos.zoom /= 0.7;
	else if (keysym == 'n')
		data->iter += 10;
	else if (keysym == 'm' && data->iter > 10)
		data->iter -= 10;
	else if (keysym == 'c' && data->color_i == 3)
		data->color_i = -1;
	if (keysym == 'c')
		data->color_i++;
	iterate_screen(data);
	return (keysym);
}
/*
Si mouse_code es 4, se hace zoom in (acercar) multiplicando data->pos.zoom por 0.7.
Si mouse_code es 5, se hace zoom out (alejar) dividiendo data->pos.zoom por 0.7.
Ajuste de la posición en el eje X:

Si se hace zoom in (mouse_code == 4 o mouse_code == 1) y el cursor está a la derecha del centro de la pantalla (x > WIDTH / 2), se incrementa data->pos.x en data->pos.zoom * 0.2.
Si se hace zoom out (mouse_code == 5) y el cursor está a la izquierda del centro de la pantalla (x < WIDTH / 2), también se incrementa data->pos.x en data->pos.zoom * 0.2.
En los casos contrarios, se decrementa data->pos.x en data->pos.zoom * 0.2.
Ajuste de la posición en el eje Y:

Si se hace zoom in (mouse_code == 4 o mouse_code == 1) y el cursor está por encima del centro de la pantalla (y < HEIGHT / 2), se decrementa data->pos.y en data->pos.zoom * 0.2.
Si se hace zoom out (mouse_code == 5) y el cursor está por debajo del centro de la pantalla (y > HEIGHT / 2), también se decrementa data->pos.y en data->pos.zoom * 0.2.
En los casos contrarios, se incrementa data->pos.y en data->pos.zoom * 0.2.
*/

int	mouse_hook(int mouse_code, int x, int y, t_data *data)
{
	if (mouse_code == 4)
		data->pos.zoom *= 0.7;
	if (mouse_code == 5)
		data->pos.zoom /= 0.7;
	if (((mouse_code == 4 || mouse_code == 1) && x > WIDTH / 2)
		|| (mouse_code == 5 && x < WIDTH / 2))
		data->pos.x += data->pos.zoom * 0.2;
	if (((mouse_code == 4 || mouse_code == 1) && x < WIDTH / 2)
		|| (mouse_code == 5 && x > WIDTH / 2))
		data->pos.x -= data->pos.zoom * 0.2;
	if (((mouse_code == 4 || mouse_code == 1) && (y < HEIGHT / 2))
		|| (mouse_code == 5 && y > HEIGHT / 2))
		data->pos.y -= data->pos.zoom * 0.2;
	if (((mouse_code == 4 || mouse_code == 1) && (y > HEIGHT / 2))
		|| (mouse_code == 5 && y < HEIGHT / 2))
		data->pos.y += data->pos.zoom * 0.2;
	iterate_screen(data);
	return (mouse_code);
}
