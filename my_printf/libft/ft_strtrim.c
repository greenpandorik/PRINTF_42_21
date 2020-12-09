/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 10:00:40 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:10:08 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search(char ch, char const *set)
{
	int counter;

	counter = 0;
	while (set[counter] != '\0')
	{
		if ((unsigned char)set[counter] == (unsigned char)ch)
			return (1);
		counter++;
	}
	return (0);
}

static int	check_before(char const *s1, char const *set)
{
	int counter;
	int res;

	counter = 0;
	res = 0;
	while (s1[counter] != '\0' && search(s1[counter], set) != 0)
		counter++;
	return (counter);
}

static int	check_after(char const *s1, char const *set)
{
	int counter;
	int size;

	size = 0;
	counter = ft_strlen(s1) - 1;
	while (counter > 0 && search(s1[counter], set) != 0)
	{
		counter--;
		size++;
	}
	return (size);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	size_beg;
	size_t	size_end;
	size_t	counter;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	size_beg = check_before(s1, set);
	size_end = check_after(s1, set);
	counter = 0;
	if (size_beg == ft_strlen(s1))
		return (ft_strdup(""));
	if (!(new = (char *)malloc(ft_strlen(s1) - size_beg - size_end + 1)))
		return (NULL);
	while (counter < ft_strlen(s1) - size_beg - size_end)
	{
		new[counter] = s1[counter + size_beg];
		counter++;
	}
	new[counter] = '\0';
	return (new);
}
