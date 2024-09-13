/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_Num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <oalsadi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:17:46 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/05/26 14:15:10 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_num(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len += ft_printf_char('0');
	if (n == -2147483648)
	{
		len += ft_printf_str("-2147483648");
		return (len);
	}
	if (n < 0)
	{
		len += ft_printf_char('-');
		n = -n;
	}
	if (n > 0)
	{
		len += ft_printf_unsigned((unsigned int) n);
	}
	return (len);
}
