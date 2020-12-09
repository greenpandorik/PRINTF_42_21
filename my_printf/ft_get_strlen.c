/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:00:51 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:08:13 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_string_nb(t_data *data)
{
	char *s;

	s = NULL;
	if (data->convers == 'd' || data->convers == 'i')
		s = ft_itoa((int)data->arg);
	else if (data->convers == 'u')
		s = ft_unsigned_itoa((unsigned int)data->arg);
	else if (data->convers == 'x' || data->convers == 'X')
		s = ft_itox((unsigned int)data->arg, data);
	else if (data->convers == 'p')
		s = ft_ultox((unsigned long)data->arg);
	else if (ft_is_convers(data->convers) == 0)
	{
		s = &data->convers;
		s[1] = '\0';
	}
	return (s);
}

int		ft_strlen_mod(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (6);
	while (s[i])
		i++;
	return (i);
}

int		ft_get_strlen(t_data *data)
{
	if (data->convers == 'c')
		return (1);
	else if (data->convers == 's')
		return (ft_strlen_mod((char *)data->arg));
	else if (data->convers == 'p')
		return (ft_strlen_mod(ft_ultox((unsigned long)data->arg)) + 2);
	else if (data->convers == 'd' || data->convers == 'i')
		return (ft_strlen_mod(ft_itoa((int)data->arg)));
	else if (data->convers == 'u')
		return (ft_strlen_mod(ft_unsigned_itoa((int)data->arg)));
	else if (data->convers == 'x' || data->convers == 'X')
		return (ft_strlen_mod(ft_itox((unsigned int)data->arg, data)));
	else if (ft_is_convers(data->convers) == 0)
		return (1);
	return (0);
}
