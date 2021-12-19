/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:38:16 by ahaifoul          #+#    #+#             */
/*   Updated: 2021/11/23 11:35:20 by ahaifoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf( const char *format, ...);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		put_unsi_nbr(unsigned long int nb);
int		str_len(char *str);
long	get_len(long nb);
int		base_convert_p(void *x);
int		ft_itoa(long n);
int		base_convert_x(long n);
int		base_convert_up(long n);
int		base_convert_hex(long int nb, char c);

#endif
