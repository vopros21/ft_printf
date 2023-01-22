/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkostenk <mkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:12:09 by mkostenk          #+#    #+#             */
/*   Updated: 2023/01/20 18:45:26 by mkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_sc
{
	int	len;
	int	ammount;
	int	pre_dot_ammount;
	int	wd_size;
	int	hex_size;
	int	flag_plus;
	int	flag_space;
	int	d_size;
}				t_sc;

void		ft_init(t_sc *sc);
void		ft_index_innit(int *a, int *b);
char		*ft_read(va_list valist, const char *s, int *flags, t_sc *sc);

int			ft_printf(const char *s, ...);
void		ft_check_data(int ptr, va_list valist, t_sc *sc, int *flags);
int			ft_putchar(char c, t_sc *sc);
int			ft_putstr(char *str);
void		ft_putptr(unsigned long long nbr, int *flags, t_sc *sc);
void		ft_putdecimal(int nbr, int *flags, t_sc *sc);
int			ft_nbrlen(int n);
int			ft_ui_nbrlen(unsigned int n);
int			ft_abs(int nbr);
int			ft_puthex(unsigned long nbr, int f, int *flags, t_sc *sc);
void		ft_putunsigned(unsigned int nbr, int *flags, t_sc *sc);
void		ft_putnbr(int n, t_sc *sc);
char		*ft_itoa(int nbr);
char		*ft_uitoa(unsigned int nbr);
int			ft_check_flags(char c, char *str, int *result);
int			ft_strlen(char *str);
int			ft_isdigit(int c);
char		*ft_strchr(const char *s);
int			ft_amount(char *str);
int			ft_is_flag(char c);
void		ft_print_ammount(int n, t_sc *sc);
void		ft_print_0x(int *f, int str_len, t_sc *sc);
char		*ft_check_dot(char *s, char *aux, t_sc *sc, int *flags);
void		ft_char(char c, int *flags, t_sc *sc);

void		ft_bzero(void *dest, size_t n);
void		*ft_memset(void *str, int c, size_t n);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strdup(char *src);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
void		*ft_calloc(size_t nmemb, size_t size);

char		*ft_process_minus_flag(int nbr, char *number, int *flags, t_sc *sc);
char		*ft_process_zero_flag(int n, char *number, int nbr, int *flags);
char		*ft_process_plus_flag(int nbr, char *number, int *flags, int n);
char		*ft_process_space_flag(char *number, int nbr, t_sc *sc);
char		*ft_process_dot_flag(char *number, int nbr, int size, t_sc *sc);
char		*ft_no_num_flags(char *number, int nbr, int n);
int			ft_malloc_size(int nbr, int *flags, t_sc *sc);
char		*ft_case(char *number, int nbr, int *flags, t_sc *sc);
int			ft_ifnot_size(int nbr, t_sc *sc);

void		ft_uint_dot(unsigned int nbr, t_sc *sc);
int			ft_d_size(int nbr, int nbr_len, t_sc *sc);
char		*ft_d_set(char *number, int nbr, int size, t_sc *sc);
char		ft_d_max_write(char *number, int nbr, t_sc *sc);
char		*ft_minus_dot_d(char *aux, char *number, int *flags, t_sc *sc);
char		*ft_dcpy(char *aux, char *number, int j);
char		*ft_dstr(int nbr, char *number, t_sc *sc);
int			ft_bigger(int a, int b);

void		ft_strings(char *str, int *flags, t_sc *sc);
void		ft_check_pre_dot_ammount(const char *s, t_sc *sc);
int			ft_size_delimitation(t_sc *sc, int str_len, int *flags);
char		*ft_minmax(char *dest, char *str, t_sc *sc);
char		*ft_string_minus_flag(char *dest, char *str, int *flags, t_sc *sc);
void		ft_pointer_flags(int *flags, int n, t_sc *sc);
int			ft_valid_flags_str(int *flags);
int			ft_valid_flags_nbr(int *flags);

void		ft_hflags(unsigned long nbr, int f, int *flags, t_sc *sc);
void		ft_hex_len(unsigned long nbr, int f, t_sc *sc);
void		ft_hex_minus(unsigned long nbr, int f, int *flags, t_sc *sc);
void		ft_hex_zeros(unsigned long nbr, int f, int *flags, t_sc *sc);
void		ft_hex_dot(unsigned int nbr, int f, int *flags, t_sc *sc);

char		ft_excess_minusflag(int nbr, int *i, int *j);
char		*ft_excess_plusflag(char *number, int nbr);
char		*ft_excess_noflags(char *aux, char *number, int *i);
int			ft_excess_unsigned(char *uns_int, int nbr, int *flags, t_sc *sc);

int			ft_ifnot_str(char *str, t_sc *sc);
int			ft_ifnot_strlen(char *str, int *flags, t_sc *sc);
int			ft_flag6(char *str, int *flags, t_sc *sc);
int			ft_flags56(char *str, int *flags, t_sc *sc);
char		*ft_dest(char *str, int *flags, t_sc *sc);
int			ft_same_len(char *str, t_sc *sc);
int			ft_nf6_namount(char *str, int *flags, t_sc *sc);

#endif
