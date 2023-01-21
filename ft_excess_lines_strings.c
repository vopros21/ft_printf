/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excess_lines_strings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:40:48 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:42:48 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ifnot_str(char *str, t_sc *sc)
{
	if (!str)
	{
		ft_putstr("(null)");
		sc->len += 6;
		return (0);
	}
	return (1);
}

int	ft_ifnot_strlen(char *str, int *flags, t_sc *sc)
{
	int	i;

	i = 0;
	if (!ft_strlen(str))
	{
		if (flags[6])
		{
			ft_putstr(str);
			return (0);
		}
		if (sc->ammount)
			while (i++ < sc->ammount)
				ft_putchar(' ', sc);
		ft_putstr(str);
		return (0);
	}
	return (1);
}

int	ft_flag6(char *str, int *flags, t_sc *sc)
{
	int	i;

	i = 0;
	if (flags[6])
	{
		if (!sc->pre_dot_ammount)
		{
			while (i < sc->wd_size && str[i])
				ft_putchar(str[i++], sc);
			return (0);
		}
	}
	return (1);
}

int	ft_flags56(char *str, int *flags, t_sc *sc)
{
	int	i;

	i = 0;
	if (flags[5] && !flags[6])
	{
		ft_putstr(str);
		sc->len += ft_strlen(str);
		ft_print_ammount(sc->ammount - ft_strlen(str) + 1, sc);
		return (0);
	}
	else if (flags[5] && flags[6])
	{
		while (i < sc->ammount && str[i])
			ft_putchar(str[i++], sc);
		while (i++ < sc->wd_size)
			ft_putchar(' ', sc);
		return (0);
	}
	return (1);
}

char	*ft_dest(char *str, int *flags, t_sc *sc)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * sc->wd_size + 1);
	if (!dest)
		return (0);
	if (sc->wd_size == sc->pre_dot_ammount)
		ft_memset(dest, ' ', sc->wd_size);
	if (flags[6])
		dest = ft_string_minus_flag(dest, str, flags, sc);
	return (0);
}
