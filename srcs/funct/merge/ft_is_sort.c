/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:07:16 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 17:01:13 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static int	ft_first_is_sort(t_num *tmp, int p)
{
	int cnt;

	cnt = 0;
	while (tmp->next)
	{
		if (tmp->pos != (tmp->next->pos - 1))
			return (0);
		if (tmp->pos == p || tmp->next->pos == p)
			cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

int			ft_is_sort(t_stack *a, int p)
{
	t_num	*tmp;
	int		cnt;

	tmp = a->bgn;
	cnt = 0;
	if (p == a->l - 1)
		cnt = ft_first_is_sort(tmp, p);
	else
	{
		while (tmp->pos != a->l - 1)
		{
			if (tmp->pos != (tmp->next->pos - 1))
				return (0);
			if (tmp->pos == p || tmp->next->pos == p)
				cnt++;
			tmp = tmp->next;
		}
	}
	if (cnt > 0)
		return (1);
	return (0);
}
