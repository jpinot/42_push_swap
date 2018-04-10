/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:22:44 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 18:57:32 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

t_num	*ft_lstnew_num(int num, t_num *p)
{
	t_num *list;

	if (!(list = (t_num *)malloc(sizeof(t_num))))
		return (NULL);
	if (p != NULL)
		list->prev = p;
	else
		list->prev = NULL;
	list->num = num;
	list->g = -1;
	list->p = -1;
	list->pos = -1;
	list->m = -1;
	list->next = NULL;
	return (list);
}
