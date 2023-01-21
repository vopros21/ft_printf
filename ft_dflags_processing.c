/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflags_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:02:11 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:38:06 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dcpy(char *aux, char *number, int j)
{
	int	i;

	i = 0;
	if (aux[i] == '-')
			i++;
	while (aux[i])
		number[j++] = aux[i++];
	return (number);
}

char	*ft_dstr(int nbr, char *number, t_sc *sc)
{
	int		i;
	int		j;
	char	*aux;

	aux = ft_itoa(nbr);
	ft_index_innit(&i, &j);
	if (sc->flag_space)
		i++;
	while (i < sc->pre_dot_ammount - sc->ammount)
		number[i++] = ' ';
	while (j++ < sc->ammount - ft_strlen(aux))
		number[i++] = '0';
	j = 0;
	while (aux[j])
		number[i++] = aux[j++];
	number[i] = '\0';
	free(aux);
	sc->flag_space = 0;
	return (number);
}
