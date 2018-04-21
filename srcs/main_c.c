/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:49:01 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/21 18:06:03 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int		main(int ac, char **av)
{
	char	**str;
	int		i;
	int		p;
	t_num	*num;
	t_num	*bgn;

	p = 0;
	i = 0;
	if (ac < 2)
		return (-1);
	else if (ac == 2)
		str = ft_strsplit(av[1], ' ');
	else
	{
		if (ft_strcmp(av[1], "-v"))
		{
			p = 1;
			str++;
		}
		if (ft_strcmp(av[1], "-c"))
		{
			p = 2;
			str++;
		}
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
	if (ac != 2)
		ft_strdel(str);
	return (checker(bgn, p));
}
