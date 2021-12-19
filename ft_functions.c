/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:29:23 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/23 12:10:54 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	base_convert_x(long int nb)
{
	int		j;
	int		tab[100];
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	j = 0;
	if (nb == 0)
		i += ft_putchar(base[0]);
	if (nb < 0)
	{
		tab[0] = '-';
		j++;
		nb = -nb;
	}
	while (nb)
	{
		tab[j++] = nb % 16;
		nb = nb / 16;
	}
	while (--j >= 0)
		i += ft_putchar(base[tab[j]]);
	return (i);
}

int	base_convert_up(long int nb)
{
	int		j;
	int		tab[100];
	int		i;
	char	*base;

	base = "0123456789ABCDEF";
	i = 0;
	j = 0;
	if (nb == 0)
		i += ft_putchar(base[0]);
	if (nb < 0)
	{
		tab[0] = '-';
		j++;
		nb = -nb;
	}
	while (nb)
	{
		tab[j++] = nb % 16;
		nb = nb / 16;
	}
	while (--j >= 0)
		i += ft_putchar(base[tab[j]]);
	return (i);
}
