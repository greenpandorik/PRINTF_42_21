/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 21:12:41 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:12:23 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*overlap(void *dst, const void *src, size_t len)
{
	size_t			counter;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = (unsigned char*)dst;
	src_tmp = (unsigned char*)src;
	counter = len;
	while (counter > 0)
	{
		counter--;
		dst_tmp[counter] = src_tmp[counter];
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			counter;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (!(dst) && !(src))
		return (NULL);
	dst_tmp = (unsigned char*)dst;
	src_tmp = (unsigned char*)src;
	counter = 0;
	if (src == dst)
		return (dst);
	if (src > dst)
	{
		counter = 0;
		while (counter < len)
		{
			dst_tmp[counter] = src_tmp[counter];
			counter++;
		}
		return (dst);
	}
	else
		return (overlap(dst, src, len));
}
