/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 07:23:18 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:11:29 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		counter;
	char	*s1;

	counter = 0;
	s1 = (char *)s;
	while (s1[counter] && s1[counter] != '\0' && s1[counter] != c)
		counter++;
	if (s1[counter] == (unsigned char)c)
		return (&s1[counter]);
	return (NULL);
}
