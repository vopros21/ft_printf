/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excess_lines_strings2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:54:08 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:42:37 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_same_len(char *str, t_sc *sc)
{
	if (ft_strlen(str) == sc->wd_size)
	{
		ft_putstr(str);
		sc->len += ft_strlen(str);
		return (0);
	}
	return (1);
}

int	ft_nf6_nammount(char *str, int *flags, t_sc *sc)
{
	char	*dest;

	if (!flags[6] && !sc->ammount)
	{
		dest = ft_strdup((char *)str);
		ft_putstr(dest);
		sc->len += ft_strlen(dest);
		free(dest);
		return (0);
	}
	return (1);
}
