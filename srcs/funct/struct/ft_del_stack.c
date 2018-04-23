/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:32:53 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 18:39:03 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_del_stack(t_stack **lst)
{
	t_stack *b;
	t_stack *a;

	a = *lst;
	b = a->s_b;
	ft_del_num(&a->bgn);
	if (b->bgn)
		ft_del_num(&b->bgn);
	free(a);
	free(b);
	a = NULL;
	b = NULL;
}
