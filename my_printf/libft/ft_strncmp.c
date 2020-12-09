/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 08:11:04 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:10:33 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			res;

	res = 0;
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (len == 0)
		return (0);
	while (tmp1[res] == tmp2[res] && tmp1[res] != '\0' && res < len - 1)
		res++;
	return (tmp1[res] - tmp2[res]);
}
