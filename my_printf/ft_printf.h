/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:32:27 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:07:54 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

typedef struct		s_data
{
	va_list			ap;
	char			*str;
	char			*set;
	char			flags;
	int				width;
	int				precision;
	char			convers;
	void			*arg;
	char			point;
	int				return_printf;
}					t_data;

int					ft_check_string(int i, t_data *data);
int					ft_printf(const char *s, ...);
void				ft_putchar(char c, t_data *data);
void				ft_reinit_flags(t_data *data);
void				ft_init(const char *s, t_data *data);
int					ft_is_number(char c);
int					ft_is_flags(char c);
int					ft_is_convers(char c);
int					ft_is_char(char c);
int					ft_check_set(char c);
void				ft_putstr(char *s, t_data *data);
void				ft_display_management(t_data *data);
void				ft_flags_management(t_data *data);
void				ft_flags_management_integer(t_data *data);
void				ft_exception_flag_zero_integer(t_data *data);
int					ft_nb_is_negative(t_data *data);
int					ft_len_nb(t_data *data);
char				*ft_get_string_nb(t_data *data);
int					ft_strlen_nb_hex(long nb);
int					ft_get_strlen(t_data *data);
void				ft_call_flags_management(t_data *data);
int					ft_check_flags_zero(int	i, t_data *data);
int					ft_check_flags_precision(int i, t_data *data);
char				*ft_unsigned_itoa(unsigned int n);
char				*ft_strjoin_char(char *s1, char c);
char				*ft_itox(unsigned int n, t_data *data);
char				*ft_ultox(unsigned long n);
int					null_width(t_data *data, char *str);
int					ft_strlen_mod(char *s);
void				ft_extra(t_data *data, int wid, int prec, int len_nb);

#endif
