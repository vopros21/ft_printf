/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:45:46 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:44:25 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer_flags(int *flags, int n, t_sc *sc)
{
	int	i;

	i = 0;
	if (flags[5])
		if (n < sc->ammount)
			while (i++ < sc->ammount - n - 2)
				ft_putchar(' ', sc);
}
