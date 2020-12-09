/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 13:46:55 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:12:48 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			runner;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	runner = 0;
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	while (runner < n)
	{
		dst_tmp[runner] = src_tmp[runner];
		if (dst_tmp[runner] == (unsigned char)c)
			return (dst + runner + 1);
		runner++;
	}
	return (NULL);
}
