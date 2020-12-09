/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 07:49:08 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:10:16 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strrchr(const char *s, int c)
{
	int		counter;
	char	*s1;

	counter = 0;
	s1 = (char *)s;
	while (s1[counter])
		counter++;
	while (s1[counter] != (unsigned char)c && counter != 0)
		counter--;
	if (s1[counter] == (unsigned char)c)
		return (&s1[counter]);
	return (NULL);
}
