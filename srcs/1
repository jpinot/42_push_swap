/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:47:23 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/13 11:19:41 by jpinyot          ###   ########.fr       */
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
//	t_num *b = ft_sort(bgn);
//	ft_sort(bgn);
//	i = 0;
//	while (b != NULL)
//	{
//		i++;
//		ft_putnbr(b->num);
//		write (1, " ", 1);
//		b = b->next;
//	}
//		write (1, "|", 1);
//	ft_putnbr(i);
//		write (1, "|", 1);
//		write (1, "\n", 1);
//	return (0);
	return (push_swap(bgn));
}
