/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:42:18 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:08:06 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_nb_size(unsigned int nb)
{
	long size;

	size = 1;
	while (nb > 0)
	{
		nb = nb / 16;
		size++;
	}
	return (size);
}

static char		*ft_convert_int_to_char(char *str, unsigned int size,
unsigned int nb, t_data *data)
{
	char	*base;

	if (data->convers == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	str[size--] = '\0';
	while (nb > 0)
	{
		str[size] = base[nb % 16];
		nb = nb / 16;
		size--;
	}
	return (str);
}

char			*ft_itox(unsigned int n, t_data *data)
{
	unsigned int	size;
	char			*str;

	str = 0;
	size = ft_get_nb_size(n);
	if (n == 0)
		size = 2;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	if (n == 0)
	{
		str[1] = '\0';
		str[0] = '0';
	}
	else
		ft_convert_int_to_char(str, size - 1, n, data);
	return (str);
}
