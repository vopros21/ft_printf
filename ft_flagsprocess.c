/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:20:05 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:43:03 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_minus_flag(int nbr, char *number, int *flags, t_sc *sc)
{
	int		i;
	int		j;
	char	*aux;

	aux = ft_itoa(nbr);
	ft_index_innit(&i, &j);
	if (flags[6] && sc->pre_dot_ammount)
		return (number = ft_minus_dot_d(aux, number, flags, sc));
	number[i] = ft_excess_minusflag(nbr, &i, &j);
	if (sc->ammount < ft_strlen(aux))
		while (aux[j])
			number[i++] = aux[j++];
	else
	{
		while (aux[j])
			number[i++] = aux[j++];
		while (i < sc->ammount)
			number[i++] = ' ';
	}
	ft_index_innit(&flags[1], &flags[3]);
	number[i] = '\0';
	free(aux);
	return (number);
}

char	*ft_process_zero_flag(int n, char *number, int nbr, int *flags)
{
	int		i;
	char	*aux;

	aux = ft_itoa(nbr);
	i = 0;
	n -= ft_strlen(aux);
	if (nbr < 0)
		n++;
	ft_memset(number, '0', n);
	if (aux[i] == '-')
	{
		number[i] = aux[i];
		i++;
	}
	else if (flags[3])
		number[i] = ' ';
	if (number[0] == '+')
		n++;
	while (aux[i])
		number[n++] = aux[i++];
	number[n] = '\0';
	free(aux);
	return (number);
}

char	*ft_process_plus_flag(int nbr, char *number, int *flags, int n)
{
	char	*aux;
	int		i;

	ft_index_innit(&i, &flags[3]);
	aux = ft_itoa(nbr);
	if (!flags[1])
		ft_memset(number, ' ', n);
	else
		number = ft_excess_plusflag(number, nbr);
	if (nbr >= 0)
		ft_memset(number, '+', 1);
	else
	{
		ft_memset(number, '-', 1);
		i++;
	}
	while (aux[i])
		number[n++ - ft_strlen(aux)] = aux[i++];
	number[n - ft_strlen(aux)] = '\0';
	free(aux);
	return (number);
}

char	*ft_process_space_flag(char *number, int nbr, t_sc *sc)
{
	char	*aux;
	int		len;
	int		i;

	i = 0;
	sc->flag_space = 1;
	aux = ft_itoa(nbr);
	len = ft_strlen(aux);
	ft_memset(number, ' ', sc->d_size);
	while (aux[i])
		number[sc->d_size++ - len] = aux[i++];
	number[sc->d_size - len] = '\0';
	free(aux);
	return (number);
}

char	*ft_no_num_flags(char *number, int nbr, int n)
{
	int		i;
	char	*aux;

	if (!nbr)
		return (NULL);
	aux = ft_itoa(nbr);
	i = 0;
	if (ft_strlen(aux) > n)
		number = ft_excess_noflags(aux, number, &i);
	else if (n)
	{
		ft_memset(number, ' ', n);
		while (number[n - ft_strlen(aux)])
			number[n++ - ft_strlen(aux)] = aux[i++];
	}
	else
		while (aux[i])
			number[n++] = aux[i++];
	number[n] = '\0';
	free(aux);
	return (number);
}
