/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:55:04 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 10:50:38 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_nb_size(unsigned long nb)
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

static char		*ft_convert_int_to_char(char *str, unsigned long size,
unsigned long nb)
{
	char	*base;

	base = "0123456789abcdef";
	str[size--] = '\0';
	while (nb > 0)
	{
		str[size] = base[nb % 16];
		nb = nb / 16;
		size--;
	}
	return (str);
}

char			*ft_ultox(unsigned long n)
{
	unsigned long	size;
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
		ft_convert_int_to_char(str, size - 1, n);
	return (str);
}
