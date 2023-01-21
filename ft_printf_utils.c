/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:12:52 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:46:58 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_sc *sc)
{
	write(1, &c, 1);
	sc->len++;
	return (1);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

void	ft_putunsigned(unsigned int nbr, int *flags, t_sc *sc)
{
	char	*uns_int;

	uns_int = ft_uitoa(nbr);
	if (!flags[5] && !flags[1] && !flags[6])
		ft_putstr(uns_int);
	else if (!ft_excess_unsigned(uns_int, nbr, flags, sc))
		return ;
	sc->len += ft_strlen(uns_int);
	free(uns_int);
}
