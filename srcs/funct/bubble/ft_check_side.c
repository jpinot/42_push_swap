/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:32:17 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/09 18:21:45 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_check_side(t_stack *s, int pos)
{
	t_num	*tmp;
	int		i;

	tmp = s->bgn;
	i = 0;
	while (tmp->pos != pos)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > (s->l) / 2)
		return (2);
	else
		return (1);
}

int	ft_check_side_g(t_stack *s, int g)
{
	t_num	*tmp;
	int		i;

	tmp = s->bgn;
	i = 0;
	while (tmp->g != g)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > (s->l) / 2)
		return (2);
	else
		return (1);
}
