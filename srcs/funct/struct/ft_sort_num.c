/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:23:28 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 18:16:49 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static void		ft_move_minor(t_num *mv, t_num *tmp)
{
	mv->next = tmp->next;
	mv->prev = tmp;
	tmp->next = mv;
	tmp = mv->next;
	tmp->prev = mv;
}

static t_num	*ft_move(t_num *mv)
{
	t_num	*tmp;

	tmp = mv->prev;
	tmp->next = NULL;
	while (tmp != NULL)
	{
		if (tmp->num < mv->num)
		{
			ft_move_minor(mv, tmp);
			break ;
		}
		if (tmp->prev == NULL)
		{
			tmp->prev = mv;
			mv->prev = NULL;
			mv->next = tmp;
			break ;
		}
		tmp = tmp->prev;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_num			*ft_sort(t_num *num)
{
	t_num	*arr;
	t_num	*tmp;
	int		i;

	i = 0;
	tmp = num;
	arr = ft_lstnew_num(tmp->num, NULL);
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (!(arr->next = ft_lstnew_num(tmp->num, arr)))
			return (NULL);
		if (arr->num > arr->next->num)
			arr = ft_move(arr->next);
		else
			arr = arr->next;
		tmp = tmp->next;
	}
	while (arr->prev != NULL)
		arr = arr->prev;
	return (arr);
}
