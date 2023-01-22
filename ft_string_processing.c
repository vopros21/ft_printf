/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:42:21 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:47:26 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strings(char *str, int *flags, t_sc *sc)
{
	char	*dest;

	if (!ft_ifnot_str(str, sc))
		return ;
	if (!sc->ammount && flags[6])
		return ;
	sc->wd_size = ft_size_delimitation(sc, ft_strlen(str), flags);
	if (!ft_ifnot_strlen(str, flags, sc))
		return ;
	if (!ft_flag6(str, flags, sc))
		return ;
	if (!ft_same_len(str, sc))
		return ;
	if (!ft_flags56(str, flags, sc))
		return ;
	if (!ft_nf6_namount(str, flags, sc))
		return ;
	dest = ft_dest(str, flags, sc);
	free(dest);
}

char	*ft_minmax(char *dest, char *str, t_sc *sc)
{
	if (sc->wd_size == sc->pre_dot_ammount)
	{
		if (sc->ammount < ft_strlen(str))
			ft_strlcpy(dest + ft_strlen(dest) - sc->ammount,
				str, (sizeof(char) * sc->ammount + 1));
		else
		{
			ft_memset(dest, ' ', sc->pre_dot_ammount);
			ft_strlcpy(dest + ft_strlen(dest) - ft_strlen(str) - 1,
				str, (sizeof(char) * sc->ammount));
		}
	}
	else
		ft_strlcpy(dest, str, (sizeof(char) * sc->ammount + 1));
	dest[sc->wd_size] = '\0';
	return (dest);
}

int	ft_size_delimitation(t_sc *sc, int str_len, int *flags)
{
	int	size;

	size = 0;
	if (sc->pre_dot_ammount || flags[6])
	{
		if (!sc->pre_dot_ammount)
			return (sc->ammount);
		if (sc->pre_dot_ammount < str_len)
			size = str_len;
		else if (sc->ammount > sc->pre_dot_ammount)
			size = sc->ammount;
		else
			size = sc->pre_dot_ammount;
	}
	else
	{
		if (str_len > sc->ammount)
			size = str_len;
		else
			size = sc->ammount;
	}
	return (size);
}

void	ft_check_pre_dot_ammount(const char *s, t_sc *sc)
{
	int			temp;
	static int	dot;

	temp = 0;
	while (temp <= dot)
	{
		if (*s == '.')
			s++;
		while (*s != '.')
			s++;
		temp++;
	}
	if (*s == '.')
	{
		s--;
		while (ft_isdigit(*s))
			s--;
		s++;
		if (*s == '0')
			exit(EXIT_FAILURE);
		sc->pre_dot_ammount = ft_amount((char *)s);
		while (*s != '.')
			s++;
	}
	dot = temp;
}

char	*ft_string_minus_flag(char *dest, char *str, int *flags, t_sc *sc)
{
	if (flags[6])
	{
		if (flags[5])
		{
			ft_strlcpy(dest, str, sc->ammount + 1);
			ft_memset(dest + ft_strlen(dest), ' ', sc->ammount);
		}
		else
			dest = ft_minmax(dest, str, sc);
	}
	else
		ft_strlcpy(dest, str, (sizeof(char) * sc->ammount + 1));
	dest[sc->wd_size] = '\0';
	return (dest);
}
