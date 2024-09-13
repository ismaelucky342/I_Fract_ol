/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_Unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <oalsadi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 00:31:33 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/05/26 14:16:45 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len += ft_printf_char('0');
	}
	else
	{
		if (n / 10 != 0)
		{
			ft_printf_unsigned (n / 10);
		}
		ft_printf_char(n % 10 + '0');
		while (n > 0)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}
