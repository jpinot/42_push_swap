/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_one_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:41:07 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/19 20:54:29 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_stack	*ft_two_num(t_stack *a, t_ret ret)
{
	if (a->bgn->p > a->end->p)
	{
		write(1, "*", 1);
		ft_sa(a, ret);
	}
	return (a);
}

static t_stack	*ft_three_num(t_stack *a, t_ret ret)
{
	if (a->bgn->p > a->bgn->next->p && a->bgn->p > a->end->p)
	   ft_ra(a, ret);	
	if (a->bgn->p > a->bgn->next->p && a->bgn->p < a->end->p)
		ft_sa(a, ret);
	if (a->bgn->next->p > a->bgn->p && a->bgn->next->p > a->end->p)
	{
		ft_sa(a, ret);
		ft_ra(a, ret);
	}
	if (a->bgn->p > a->bgn->next->p)
		ft_sa(a, ret);
	return (a);
}

t_stack	*ft_group_one_sort(t_stack *a, t_stack *b, t_ret ret)
{
//	write(1, "$", 1);
	if (a->bgn->next == NULL)
		return (a);
	else if (a->bgn->next->next == NULL)
		return (ft_two_num(a, ret));
	else if (a->bgn->next->next->next == NULL)
		return (ft_three_num(a, ret));
	if (b->bgn != NULL)
		return (a);
	return (a);
}
