/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:47:23 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/26 17:51:37 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int		main(int ac, char **av)
{
	char	**str;
	t_list	*num;
	t_list	*bgn;

	i = 0;
	if (ac < 2)
		return (-1);
	else if (ac == 2)
		str = ft_strsplit(av[1], ' ');
	else if (ac > 2)
	{
		str = av;
		str++;
	}
	bgn = num;
	while (str[i])
	{
		if ((num->next = ft_lstnew_num(ft_atoi(str[i]), 0)) == NULL)
			return (NULL);
		num = num->next;
	}
	push_swap(bgn, num, i);
}
