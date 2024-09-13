/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_Pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <oalsadi-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 01:23:38 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/05/24 14:06:56 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_long_num_ptr(unsigned long long ptr);
static void	ft_search_hexa_ptr(unsigned long long ptr);

int	ft_printf_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += ft_printf_str("0x");
	if (ptr == 0)
	{
		len += ft_printf_char('0');
	}
	else
	{
		ft_search_hexa_ptr(ptr);
		len += ft_long_num_ptr(ptr);
	}
	return (len);
}

static	void	ft_search_hexa_ptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_search_hexa_ptr(ptr / 16);
		ft_search_hexa_ptr(ptr % 16);
	}
	else
	{
		if (ptr < 10)
		{
			ft_printf_char(ptr + '0');
		}
		else
		{
			ft_printf_char(ptr - 10 + 'a');
		}
	}
}

static	int	ft_long_num_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}
