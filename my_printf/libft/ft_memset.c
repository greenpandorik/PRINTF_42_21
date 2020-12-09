/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:32:43 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:12:15 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	size_t			counter;
	unsigned char	*dst_tmp;

	counter = 0;
	dst_tmp = (unsigned char *)dst;
	while (counter < n)
	{
		dst_tmp[counter] = c;
		counter++;
	}
	return (dst);
}
