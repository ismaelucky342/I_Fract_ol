/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_Hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <oalsadi-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 01:35:32 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/05/24 14:06:16 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_long_num(unsigned int n);
static	void	ft_search_hexa(unsigned int a, const char b);

int	ft_printf_hexa(unsigned int a, const char b)
{
	if (a == 0)
		return (ft_printf_char('0'));
	else
		ft_search_hexa(a, b);
	return (ft_long_num(a));
}

static	void	ft_search_hexa(unsigned int a, const char b)
{
	if (a >= 16)
	{
		ft_search_hexa(a / 16, b);
		ft_search_hexa(a % 16, b);
	}
	else
	{
		if (a < 10)
		{
			ft_printf_char(a + '0');
		}
		else
		{
			if (b == 'X')
			{
				ft_printf_char(a - 10 + 'A');
			}
			if (b == 'x')
			{
				ft_printf_char(a - 10 + 'a');
			}
		}
	}
}

static	int	ft_long_num(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}
