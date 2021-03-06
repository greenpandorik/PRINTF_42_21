/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:38:02 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:09:07 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_call_flags_management(t_data *data)
{
	int	n;

	n = 0;
	while (data->set[n++])
	{
		if (ft_is_char(data->set[n]))
		{
			data->convers = data->set[n];
			ft_flags_management(data);
			break ;
		}
		else if (data->set[n + 1] == '\0')
		{
			ft_flags_management(data);
			n++;
		}
	}
	if (data->set)
		free(data->set);
}

int		ft_check_flags_zero(int i, t_data *data)
{
	if (data->set[i] == '0' && data->flags != '-')
	{
		data->width = 0;
		data->flags = '0';
		i++;
		if (data->set[i] >= '0' && data->set[i] <= '9')
			while (data->set[i] >= '0' && data->set[i] <= '9')
				data->width = data->width * 10 + (data->set[i++] - '0');
		else if (data->set[i] == '*')
		{
			i++;
			data->width = va_arg(data->ap, int);
			if (data->width < 0)
			{
				data->flags = '-';
				data->width = data->width * -1;
			}
		}
	}
	return (i);
}

int		ft_check_flags_precision(int i, t_data *data)
{
	if (data->set[i] == '.')
	{
		i++;
		if (data->set[i] != '*')
		{
			data->precision = 0;
			while (data->set[i] >= '0' && data->set[i] <= '9')
				data->precision = data->precision *
					10 + (data->set[i++] - '0');
		}
		else if (data->set[i++] == '*')
		{
			data->precision = va_arg(data->ap, int);
			if (data->precision < 0)
				data->precision = -1;
		}
	}
	return (i);
}
