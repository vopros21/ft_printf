/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022-12-26 21:42:09 by mkostenk          #+#    #+#             */
/*   Updated: 2022-12-26 21:44:38 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_converthex(long long int nbr, char frmt)
{
	char	*base;

	base = "0123456789abcdef";
	if (frmt == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 0)
		nbr = (4294967295 + nbr) + 1;
	if (nbr >= 16)
		ft_converthex(nbr / 16, frmt);
	write (1, &base[nbr % 16], 1);
}
