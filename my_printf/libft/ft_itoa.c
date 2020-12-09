/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 13:28:12 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:13:21 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenght(int n)
{
	int tmp;
	int counter;

	counter = 0;
	tmp = n;
	while (tmp > 9 || tmp < -9)
	{
		tmp = tmp / 10;
		counter++;
	}
	if (tmp < 0)
		return (counter + 1);
	return (counter + 1);
}

static char	*otric(int n)
{
	int		ogranic;
	int		len;
	char	*s;

	len = lenght(n) + 1;
	if (!(s = (char *)malloc(len + 1)))
		return (NULL);
	s[len] = '\0';
	s[0] = '-';
	ogranic = 1;
	if (n == -2147483648)
	{
		ogranic = 2;
		s[1] = '2';
		n = n + 2000000000;
	}
	n = n * -1;
	while (len > ogranic)
	{
		len--;
		s[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char	*a;
	int		len;

	len = lenght(n);
	if (n < 0)
		return (otric(n));
	a = (char *)malloc(len + 1);
	if (!a)
		return (NULL);
	a[len] = '\0';
	while (len > 0)
	{
		len--;
		a[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (a);
}
