/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:47:52 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/23 12:11:23 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

long	get_len(long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_itoa(long nb)
{
	long		i;
	char		*new;

	i = get_len(nb);
	new = (char *)malloc(sizeof (char) * (i + 1));
	if (new == NULL)
		return (0);
	new[i] = '\0';
	i--;
	if (nb < 0)
	{
		nb *= -1;
		new[0] = '-';
	}
	while (nb > 9)
	{
		new [i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	new[i] = nb + 48;
	i = ft_putstr(new);
	free (new);
	return (i);
}
