/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:53:01 by jpinyot           #+#    #+#             */
/*   Updated: 2018/05/31 20:15:39 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static int	checkdigit(const char *str)
{
	int i;
	int cnt;

	i = -1;
	while (str[++i] == '0')
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (ft_isdigit(str[i]) == 0)
			return (-1);
	}
	cnt = i;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			return (-1);
	if (i - cnt > 11)
		return (-1);
	return (0);
}

int			ft_atoi_ps(const char *str)
{
	long	n;
	size_t	i;
	size_t	neg;

	n = 0;
	i = 0;
	neg = 0;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			neg++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = (10 * n) + (str[i] - 48);
		i++;
	}
	if (neg > 0)
		n *= -1;
	if (n > 2147483647 || n < -2147483648 || checkdigit(str) == -1)
		return (-1);
	return (0);
}
