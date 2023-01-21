/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:51:53 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:46:42 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, t_sc *sc)
{
	if (n == -2147483648)
	{
		ft_putchar('-', sc);
		ft_putchar('2', sc);
		ft_putnbr(147483648, sc);
	}
	else if (n < 0)
	{
		n = n * -1;
		ft_putchar('-', sc);
		ft_putnbr(n, sc);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, sc);
		ft_putnbr(n % 10, sc);
	}
	else
		ft_putchar(n + '0', sc);
}

void	ft_putdecimal(int nbr, int *flags, t_sc *sc)
{
	char	*number;

	ft_valid_flags_nbr(flags);
	sc->d_size = ft_malloc_size(nbr, flags, sc);
	sc->d_size = ft_malloc_size(nbr, flags, sc);
	number = ft_calloc((sc->d_size + 1), sizeof(char));
	if (!number)
		return ;
	if (!sc->ammount && !flags[6] && !flags[3] && !flags[4])
	{
		ft_putnbr(nbr, sc);
		free(number);
		return ;
	}
	number = ft_case(number, nbr, flags, sc);
	ft_putstr(number);
	sc->len += ft_strlen(number);
	sc->d_size = 0;
	sc->flag_plus = 0;
	free(number);
}

int	ft_malloc_size(int nbr, int *flags, t_sc *sc)
{
	if (!sc->d_size)
		return (ft_ifnot_size(nbr, sc));
	if (flags[3] && !flags[1])
	{
		if (sc->d_size < 2 && ft_nbrlen(nbr) == 1)
			sc->d_size = 2;
		else if (sc->d_size <= ft_nbrlen(nbr) && nbr >= 0)
			sc->d_size++;
		return (sc->d_size);
	}
	if (flags[6])
	{
		sc->d_size = ft_d_size(nbr, ft_nbrlen(nbr), sc);
		if (flags[4])
		{
			sc->flag_plus = 1;
			sc->d_size++;
		}
		return (sc->d_size);
	}
	if (flags[4] && !flags[1])
		return (sc->d_size + 1);
	return (sc->d_size);
}

char	*ft_case(char *number, int nbr, int *flags, t_sc *sc)
{
	if (flags[5])
		number = ft_process_minus_flag(nbr, number, flags, sc);
	if (flags[1])
		number = ft_process_zero_flag(sc->d_size, number, nbr, flags);
	if (flags[4] && !flags[6])
		number = ft_process_plus_flag(nbr, number, flags, sc->d_size);
	if (flags[3] && !flags[1])
		number = ft_process_space_flag(number, nbr, sc);
	if (flags[6])
		number = ft_process_dot_flag(number, nbr, sc->d_size, sc);
	if (!flags[1] && !flags[2] && !flags[3]
		&& !flags[4] && !flags[5] && !flags[6])
		number = ft_no_num_flags(number, nbr, sc->d_size);
	return (number);
}

int	ft_ifnot_size(int nbr, t_sc *sc)
{
	if (ft_nbrlen(nbr) > sc->ammount)
		return (ft_nbrlen(nbr));
	else
		return (sc->ammount);
}
