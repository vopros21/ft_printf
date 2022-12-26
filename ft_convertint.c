/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022-12-26 21:42:09 by mkostenk          #+#    #+#             */
/*   Updated: 2022-12-26 21:44:38 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_convertint(int nbr)
{
	char	*base;
	int		len;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	base = "0123456789";
	len = 1;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		len += 1;
	}
	if (nbr > 9)
		len += ft_convertint(nbr / 10);
	write(1, &base[nbr % 10], 1);
	return (len);
}
