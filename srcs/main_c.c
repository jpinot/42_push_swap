/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:49:01 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/23 21:07:34 by jpinyot          ###   ########.fr       */
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

static int	ft_flag_chkr(t_flag *flag,char **av)
{
	int i;
	
	i = 1;
	flag->v = 0;
	flag->l = 0;
	flag->o = 0;
	flag->m = 0;
	flag->p = 0;
	flag->s = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "-p") == 0)
			flag->p = 1;
		else if (ft_strcmp(av[i], "-m") == 0)
			flag->m = 1;
		else if (ft_strcmp(av[i], "-o") == 0)
			flag->o = 1;
		else if (ft_strcmp(av[i], "-v") == 0)
			flag->v = 1;
		else if (ft_strcmp(av[i], "-c") == 0)
			flag->v = 2;
		else if (ft_strcmp(av[i], "-l") == 0)
			flag->l = 1;
		else if (ft_strcmp(av[i], "-s") == 0)
			flag->s = 1;
		else
			return (i);
		i++;
	}
	return (-1);
}

int		main(int ac, char **av)
{
	char	**str;
	int		i;
	t_flag	flag;
	t_num	*num;
	t_num	*bgn;

	if (ac < 2)
		return (-1);
	else if (ac == 2)
		str = ft_strsplit(av[1], ' ');
	else
	{
		if ((i = ft_flag_chkr(&flag, av)) > 1 && av[i + 1] == NULL)
			str = ft_strsplit(av[i], ' ');
		else
		{
			str = av;
			str += i;
		}
	}
	i = 0;
	if (ft_atoi_ps(str[i]) == -1)
	{
		ft_dprintf(2, "Error\n");
//		ft_strdel(str);
		return (-1);
	}
	if ((num = ft_lstnew_num(ft_atoi(str[i]), NULL)) == NULL)
		return (-1);
	bgn = num;
	while (str[++i])
	{
		if (ft_atoi_ps(str[i]) == -1)
		{
			i = -1;
			break ;
		}
		if ((num->next = ft_lstnew_num(ft_atoi(str[i]), num)) == NULL)
			return (-1);
		num = num->next;
	}
	if (ft_check_repeat(bgn, str) == 0 || i == -1)
	{
		ft_dprintf(2, "Error\n");
//		ft_strdel(str);
		ft_del_num(&bgn);
		return (-1);
	}
//	if (ac == 2)   pensaaa
//		ft_strdel(str);
	return (checker(bgn, flag));
}
