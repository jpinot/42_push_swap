/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:37:02 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/20 20:22:04 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static int	ft_check_repeat(t_num *bgn, char **str)
{
	t_num	*tmp1;
	t_num	*tmp2;
	int		i;

	tmp1 = bgn;
	i = 0;
	while(tmp1)
	{
		tmp2 = tmp1->next;
		while(tmp2)
		{
			if (tmp1->num == tmp2->num)
				return (0);

			tmp2 = tmp2->next;
		}
		if (tmp1->num == 0 && str[i][0] != 48)
			return (0);
		i++;
		tmp1 = tmp1->next;
	}
	return (1);
}

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
	if (ft_check_repeat(bgn, str) == 0)
	{
		ft_putstr("error: non valid input");
//		ft_strdel(str);
		ft_del_num(&bgn);
		return (-1);
	}
	return (push_swap(bgn));
}
