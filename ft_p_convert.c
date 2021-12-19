/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:28:38 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/23 12:11:01 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	base_convert_p(void *x)
{
	int					j;
	int					tab[100];
	unsigned long int	nb;
	int					i;
	char				*base;

	base = "0123456789abcdef";
	nb = (unsigned long int)x;
	j = 0;
	i = ft_putstr("0x");
	if (nb == 0)
		i += ft_putchar(base[0]);
	while (nb)
	{
		tab[j++] = nb % 16;
		nb = nb / 16;
	}
	while (--j >= 0)
		i += ft_putchar(base[tab[j]]);
	return (i);
}

int	base_convert_hex(long int nb, char c)
{
	char	*base;
	char	*base1;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	base1 = "0123456789ABCDEF";
	if (nb == 0)
		i += ft_putchar(base[0]);
	else if (c == 'x')
		i += base_convert_x(nb);
	else if (c == 'X')
		i += base_convert_up(nb);
	return (i);
}
