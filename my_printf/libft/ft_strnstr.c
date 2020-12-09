/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 07:54:54 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:10:25 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t lenght;

	if (*need == '\0')
		return ((char *)hay);
	lenght = ft_strlen(need);
	while (*hay != '\0' && len-- >= lenght)
	{
		if (*hay == *need && ft_memcmp(hay, need, lenght) == 0)
			return ((char *)hay);
		hay++;
	}
	return (NULL);
}
