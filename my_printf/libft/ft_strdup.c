/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 09:19:49 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:11:24 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		lenght;

	lenght = ft_strlen(s1);
	new = (char *)malloc(lenght + 1);
	if (!(new))
		return (NULL);
	new[lenght] = '\0';
	while (lenght >= 0)
	{
		new[lenght] = s1[lenght];
		lenght--;
	}
	return (new);
}
