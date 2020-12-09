/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:30:18 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 10:53:53 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_data *data)
{
	write(1, &c, 1);
	data->return_printf++;
}

void	ft_reinit_flags(t_data *data)
{
	if (!(data->set = (char *)malloc(sizeof(char *))))
		return ;
	data->set[0] = '\0';
	data->flags = '~';
	data->width = 0;
	data->precision = -1;
	data->convers = 0;
	data->arg = 0;
}

void	ft_init(const char *s, t_data *data)
{
	data->str = (char *)s;
	data->set = 0;
	data->flags = '~';
	data->width = 0;
	data->precision = -1;
	data->convers = 0;
	data->arg = 0;
	data->return_printf = 0;
}

void	ft_extra(t_data *data, int wid, int prec, int len_nb)
{
	while (wid-- > prec && wid >= len_nb)
		if (data->convers == 'p' && data->point == '.')
		{
			if (wid >= len_nb + 2)
				ft_putchar(' ', data);
		}
		else
			ft_putchar(' ', data);
	return ;
}

char	*ft_strjoin_char(char *s1, char c)
{
	int		i;
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i++] = c;
	dst[i] = '\0';
	return (dst);
}
