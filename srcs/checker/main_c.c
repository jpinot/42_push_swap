/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:49:01 by jpinyot           #+#    #+#             */
/*   Updated: 2018/05/26 15:58:46 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static int		ft_check_repeat(t_num *bgn, char **str)
{
	t_num	*tmp1;
	t_num	*tmp2;
	int		i;

	tmp1 = bgn;
	i = 0;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
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

static t_num	*ft_new_n_struct(t_num *num, char **str, int i, int ac)
{
	t_num *bgn;

	bgn = num;
	while (str[++i])
	{
		if (ft_atoi_ps(str[i]) == -1)
		{
			i = -1;
			break ;
		}
		if ((num->next = ft_lstnew_num(ft_atoi(str[i]), num)) == NULL)
			return (NULL);
		num = num->next;
	}
	if (ft_check_repeat(bgn, str) == 0 || i == -1)
	{
		ft_dprintf(2, "Error\n");
		if (ac == 2)
			ft_deldstr(str);
		ft_del_num(&bgn);
		return (NULL);
	}
	if (ac == 2)
		ft_deldstr(str);
	return (bgn);
}

int				main(int ac, char **av)
{
	char	**str;
	int		i;
	int		ac2;
	t_flag	flag;
	t_num	*num;

	i = 1;
	ac2 = ac;
	if (ac < 2)
		return (-1);
	else if (ac == 2 || ((i = ft_flag_new(&flag, av)) > 1 && av[i + 1] == NULL))
	{
		ac2 = 2;
		str = ft_strsplit(av[i], ' ');
	}
	else
		str = (av + i);
	i = ft_atoi_ps(str[0]);
	if ((num = ft_lstnew_num(ft_atoi(str[0]), NULL)) == NULL)
		return (-1);
	if (!(ft_new_n_struct(num, str, i, ac2)))
		return (-1);
	return (checker(num, flag));
}
