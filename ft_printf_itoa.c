/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:34:31 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:46:29 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int nbr)
{
	int		len;
	char	*str;

	len = ft_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
		str[0] = '-';
	else if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[--len] = ft_abs(nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_uitoa(unsigned int nbr)
{
	int		len;
	char	*str;

	len = ft_ui_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[--len] = ft_abs(nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (str);
}

int	ft_ui_nbrlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
