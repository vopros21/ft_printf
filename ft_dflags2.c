/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflags2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:45:50 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:37:10 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_minus_dot_d(char *aux, char *number, int *flags, t_sc *sc)
{
	int	i;
	int	j;
	int	size;

	if (sc->ammount < ft_strlen(aux))
		size = ft_strlen(aux);
	else
		size = sc->ammount;
	j = 0;
	i = 0;
	if (aux[0] == '-')
	{
		number[i++] = aux[j++];
		size += ft_strlen(aux) - 1;
	}
	while (i < size - ft_strlen(aux))
		number[i++] = '0';
	while (aux[j])
		number[i++] = aux[j++];
	j = 0;
	while (j++ < sc->d_size - size)
		number[i++] = ' ';
	number[i] = '\0';
	flags[6] = 0;
	return (number);
}
