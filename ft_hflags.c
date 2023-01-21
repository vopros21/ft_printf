/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:00:17 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:43:19 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hflags(unsigned long nbr, int f, int *flags, t_sc *sc)
{
	if (!flags[1] && !flags[5] && !flags[6])
		ft_puthex(nbr, f, flags, sc);
	if (flags[6])
	{
		ft_hex_dot(nbr, f, flags, sc);
		return ;
	}
	if (flags[1])
		ft_hex_zeros(nbr, f, flags, sc);
	if (flags[5])
		ft_hex_minus(nbr, f, flags, sc);
}

void	ft_hex_minus(unsigned long nbr, int f, int *flags, t_sc *sc)
{
	int		i;
	char	*aux;

	i = 0;
	aux = ft_uitoa(nbr);
	ft_puthex(nbr, f, flags, sc);
	while (i++ < sc->ammount - sc->hex_size)
		ft_putchar(' ', sc);
	free(aux);
}

void	ft_hex_zeros(unsigned long nbr, int f, int *flags, t_sc *sc)
{
	int		i;
	char	*aux;

	aux = ft_uitoa(nbr);
	i = 0;
	ft_hex_len(nbr, f, sc);
	while (i++ < sc->ammount - sc->hex_size)
		ft_putchar('0', sc);
	ft_puthex(nbr, f, flags, sc);
	free(aux);
}

void	ft_hex_dot(unsigned int nbr, int f, int *flags, t_sc *sc)
{
	if (!sc->pre_dot_ammount)
		ft_hex_zeros(nbr, f, flags, sc);
}
