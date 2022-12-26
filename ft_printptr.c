/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022-12-26 21:42:24 by mkostenk          #+#    #+#             */
/*   Updated: 2022-12-26 21:44:38 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static int	ft_lenptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

int	ft_printptr(va_list args)
{
	long long int		ptr;
	int					len;

	ptr = va_arg(args, long long int);
	write(1, "0x", 2);
	if (!ptr)
	{
		write(1, "0", 1);
		return (3);
	}
	len = ft_lenptr(ptr);
	ft_convertptr(ptr);
	return (len + 2);
}
