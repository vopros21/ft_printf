/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:58:43 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:43:31 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_sc *sc)
{
	sc->len = 0;
	sc->ammount = 0;
	sc->pre_dot_ammount = 0;
	sc->wd_size = 0;
	sc->hex_size = 0;
	sc->flag_plus = 0;
	sc->d_size = 0;
	sc->flag_space = 0;
}

void	ft_index_innit(int *a, int *b)
{
	*a = 0;
	*b = 0;
}
