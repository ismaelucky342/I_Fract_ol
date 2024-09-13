/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_Str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <oalsadi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:31:57 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/05/26 14:16:34 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *str)
{
	int	len;

	len = 0;
	if (str == 0)
	{
		return (ft_printf_str("(null)"));
	}
	while (str[len])
	{
		len += ft_printf_char(str[len]);
	}
	return (len);
}
