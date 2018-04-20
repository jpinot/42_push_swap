/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:49:01 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/20 19:14:45 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int		main(int ac, char **av)
{
	char	**str;
	int		i;
	t_num	*num;
	t_num	*bgn;

	i = 0;
	if (ac < 2)
		return (-1);
	else if (ac == 2)
		str = ft_strsplit(av[1], ' ');
	else
	{
		str = av;
		str++;
	}
	if ((num = ft_lstnew_num(ft_atoi(str[i]), NULL)) == NULL)
		return (-1);
	bgn = num;
	while (str[++i])
	{
		if ((num->next = ft_lstnew_num(ft_atoi(str[i]), num)) == NULL)
			return (-1);
		num = num->next;
	}
	return (checker(bgn));
}
