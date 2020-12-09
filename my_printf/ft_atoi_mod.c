/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maragog <maragog@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:24:45 by maragog           #+#    #+#             */
/*   Updated: 2020/08/16 13:09:13 by maragog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_mod(char *str, int *n)
{
	int i;
	int	nb;
	int	negpos;

	i = 0;
	nb = 0;
	negpos = 1;
	while ((str[i] == ' ') || (str[i] > 6 && str[i] < 14))
		i++;
	if (str[i] == '-')
		negpos = negpos * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	n = n + i;
	nb = nb * negpos;
	return (nb);
}
