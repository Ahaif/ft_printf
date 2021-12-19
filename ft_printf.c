/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:14:25 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/23 12:11:40 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid(char c)
{
	if (c == 'd' || c == 's' || c == 'i' || c == 'x' || c == 'c'
		|| c == 'X' || c == 'u' || c == 'p')
		return (1);
	return (0);
}

static int	ft_eval(va_list va, const char *format, int i)
{
	int		ret;

	ret = 0;
	if (format[i] == 'd' || format[i] == 'i')
		ret += ft_itoa(va_arg(va, int));
	else if (format[i] == 'c')
		ret += ft_putchar(va_arg(va, int));
	else if (format[i] == 's')
		ret += ft_putstr(va_arg(va, char *));
	else if (format[i] == 'p')
		ret += base_convert_p(va_arg(va, void *));
	else if (format[i] == 'u')
		ret += ft_itoa(va_arg(va, unsigned int));
	else if (format[i] == 'x' || format[i] == 'X')
		ret += base_convert_hex(va_arg(va, unsigned int), format[i]);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	va_start(va, format);
	while (format[i])
	{
		if (format[i] == '%' && is_valid(format[i + 1]))
			ret += ft_eval(va, format, ++i);
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			ret += ft_putchar(format[i]);
			i++;
		}
		else if (format[i] != '%')
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(va);
	return (ret);
}
