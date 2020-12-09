/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 02:59:36 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:11:11 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t count_dst;
	size_t count_src;

	count_dst = ft_strlen(dst);
	count_src = 0;
	if (size <= count_dst)
		return (size + ft_strlen(src));
	while ((count_src + count_dst < size - 1) && src[count_src] != '\0')
	{
		dst[count_dst + count_src] = src[count_src];
		count_src++;
	}
	dst[count_dst + count_src] = '\0';
	return (ft_strlen(src) + count_dst);
}
