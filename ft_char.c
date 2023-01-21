/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:16:30 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:36:31 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(char c, int *flags, t_sc *sc)
{
	int	i;

	i = 0;
	if (flags[5])
		ft_putchar(c, sc);
	if (sc->ammount)
		while (++i < sc->ammount)
			ft_putchar(' ', sc);
	if (!flags[5])
		ft_putchar(c, sc);
}
