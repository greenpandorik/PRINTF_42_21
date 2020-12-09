/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 15:00:36 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:12:43 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*str;

	str = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		if (str[counter] == (unsigned char)c)
			return (&str[counter]);
		counter++;
	}
	return (NULL);
}
