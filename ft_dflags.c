/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:55:32 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:37:41 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_dot_flag(char *number, int nbr, int size, t_sc *sc)
{
	int		i;
	int		j;
	int		s;
	char	*aux;

	aux = ft_itoa(nbr);
	ft_index_innit(&i, &j);
	s = ft_bigger(sc->ammount, ft_strlen(aux));
	number = ft_d_set(number, nbr, size, sc);
	if (sc->flag_plus || nbr < 0)
	{
		if (sc->pre_dot_ammount)
			while (j < size - s - ft_strlen(aux))
				number[j++] = ' ';
		number[j++] = ft_d_max_write(number, nbr, sc);
		while (i++ < s - ft_strlen(aux))
			number[j++] = '0';
		if (number[j] == '0')
			j++;
		number = ft_dcpy(aux, number, j);
	}
	else
		number = ft_dstr(nbr, number, sc);
	free(aux);
	return (number);
}

void	ft_uint_dot(unsigned int nbr, t_sc *sc)
{
	int		i;
	char	*aux;

	i = 0;
	aux = ft_uitoa(nbr);
	if (!sc->pre_dot_ammount)
	{
		while (i++ < sc->ammount - ft_strlen(aux))
			ft_putchar('0', sc);
		ft_putstr(aux);
		sc->len += ft_strlen(aux);
	}
	free(aux);
}

int	ft_d_size(int nbr, int nbr_len, t_sc *sc)
{
	int	size;

	size = 0;
	if (sc->ammount <= nbr_len && sc->pre_dot_ammount <= nbr_len)
		size = nbr_len;
	else if (sc->ammount > nbr_len && (!sc->pre_dot_ammount
			|| sc->pre_dot_ammount < sc->ammount))
		size = sc->ammount;
	else if (sc->pre_dot_ammount > nbr_len)
		size = sc->pre_dot_ammount;
	if (nbr < 0 && sc->ammount > 1)
		while (size <= sc->ammount)
			size++;
	return (size);
}

char	*ft_d_set(char *number, int nbr, int size, t_sc *sc)
{
	if (sc->pre_dot_ammount)
		ft_memset(number, ' ', size);
	if (sc->ammount && (sc->pre_dot_ammount - sc->ammount >= 0))
		ft_memset(number + (sc->pre_dot_ammount - sc->ammount), '0', size);
	if (sc->ammount && !sc->pre_dot_ammount)
	{
		if (nbr < 0)
			ft_memset(number + 1, '0', size - ft_nbrlen(nbr));
		else
			ft_memset(number, '0', size);
	}
	return (number);
}

char	ft_d_max_write(char *number, int nbr, t_sc *sc)
{
	if (sc->flag_plus)
	{
		if (nbr < 0)
			return ('-');
		else
			return ('+');
	}
	if (nbr < 0)
		return ('-');
	return (*number);
}
