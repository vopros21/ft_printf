/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022-12-26 21:42:24 by mkostenk          #+#    #+#             */
/*   Updated: 2022-12-26 21:44:38 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_checkformat(char *str, va_list args);
int		ft_printf(const char *str, ...);

// Convert

int		ft_convertint(int nbr);
int		ft_convertuns(unsigned int nbr);

void	ft_converthex(long long int nbr, char frmt);
void	ft_convertptr(unsigned long long ptr);

// Print

int		ft_printchar(va_list args);
int		ft_printhex(va_list args, char frmt);
int		ft_printint(va_list args);
int		ft_printptr(va_list args);
int		ft_printstr(va_list args);
int		ft_printuns(va_list args);

// Libft

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s);

#endif
