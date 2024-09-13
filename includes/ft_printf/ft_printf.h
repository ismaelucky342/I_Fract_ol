/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <oalsadi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 01:47:56 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/05/24 11:32:00 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf_str(char *str);
int		ft_printf_char(int c);
int		ft_printf_num(int n);
int		ft_printf_ptr(unsigned long long ptr);
int		ft_printf_hexa(unsigned int a, const char b);
int		ft_printf_unsigned(unsigned int n);
int		ft_printf(const char *str, ...);

#endif
