/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 13:36:28 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:12:31 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t			runner;
	unsigned char	*src;
	unsigned char	*dst;

	runner = 0;
	if (!(destination) && !(source))
		return (NULL);
	src = (unsigned char *)source;
	dst = (unsigned char *)destination;
	while (runner < n)
	{
		dst[runner] = src[runner];
		runner++;
	}
	return (destination);
}
