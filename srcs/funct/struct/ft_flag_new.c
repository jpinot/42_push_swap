/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 09:49:05 by jpinyot           #+#    #+#             */
/*   Updated: 2018/05/14 18:27:41 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libswap.h>

static t_flag	*init_flag(t_flag *flag)
{
	flag->v = 0;
	flag->l = 0;
	flag->o = 0;
	flag->m = 0;
	flag->p = 0;
	flag->s = 0;
	return (flag);
}

int				ft_flag_new(t_flag *flag, char **av)
{
	int i;

	i = 1;
	flag = init_flag(flag);
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
	return (1);
}
