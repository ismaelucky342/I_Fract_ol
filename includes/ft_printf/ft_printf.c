/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <oalsadi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:46:29 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/05/26 14:19:30 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(va_list arg, const char words);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start (arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_printf_format(arg, str[i + 1]);
			i++;
		}
		else
		{
			len += ft_printf_char(str[i]);
		}
		i++;
	}
	va_end(arg);
	return (len);
}

int	ft_printf_format(va_list arg, const char words)
{
	int	len;

	len = 0;
	if (words == 'c')
		len += ft_printf_char(va_arg(arg, int));
	else if (words == 'x' || words == 'X')
		len += ft_printf_hexa(va_arg(arg, unsigned int), words);
	else if (words == 'd' || words == 'i')
		len += ft_printf_num(va_arg(arg, int));
	else if (words == 'p')
		len += ft_printf_ptr(va_arg(arg, unsigned long long));
	else if (words == 's')
		len += ft_printf_str(va_arg(arg, char *));
	else if (words == 'u')
		len += ft_printf_unsigned(va_arg(arg, unsigned int));
	else
		len += ft_printf_char(words);
	return (len);
}
