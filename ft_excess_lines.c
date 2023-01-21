/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excess_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:58:29 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:40:11 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_excess_minusflag(int nbr, int *i, int *j)
{
	char	neg;

	neg = '-';
	if (nbr < 0)
	{
		*j += 1;
		*i += 1;
		return (neg);
	}
	return (0);
}

char	*ft_excess_plusflag(char *number, int nbr)
{
	if (nbr < 0)
		ft_memset(number, '-', 1);
	else
		ft_memset(number, '+', 1);
	return (number);
}

char	*ft_excess_noflags(char *aux, char *number, int *i)
{
	while (aux[*i])
	{
		number[*i] = aux[*i];
		*i += 1 ;
	}
	return (number);
}

int	ft_excess_unsigned(char *uns_int, int nbr, int *flags, t_sc *sc)
{
	int	i;

	i = 0;
	if (flags[6])
	{
		ft_uint_dot(nbr, sc);
		free(uns_int);
		return (0);
	}
	if (flags[1])
	{
		while (i++ < sc->ammount - ft_strlen(uns_int))
			ft_putchar('0', sc);
		ft_putstr(uns_int);
	}
	else
	{
		i = 0;
		ft_putstr(uns_int);
		while (i++ < sc->ammount - ft_strlen(uns_int))
			ft_putchar(' ', sc);
	}
	return (1);
}
