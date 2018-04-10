/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:18:29 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 17:38:38 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_non_major_pos(t_stack *a, int pos)
{
	t_num *tmp;

	tmp = a->bgn;
	while (tmp)
	{
		if (tmp->pos >= pos)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_non_minor_pos(t_stack *a, int pos)
{
	t_num *tmp;

	tmp = a->bgn;
	while (tmp)
	{
		if (tmp->pos < pos)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check_m(t_stack *a)
{
	t_num	*tmp;
	int		i;
	int		ref;

	tmp = a->bgn;
	ref = tmp->m;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->m != ref)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_check_pos(t_num *a, int p)
{
	t_num *tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->pos <= p)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
