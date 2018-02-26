/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:22:44 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/26 17:38:29 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_num	*ft_lstnew_num(int num, int g)
{
	t_num *list;

	if (!(list = (t_num *)malloc(sizeof(t_num))))
		return (NULL);
	if (!(list->num = (int)malloc(sizeof(int)))
		return (NULL);
	list->g = g;
	list->num = num;
	list->next = NULL;
	return (list);
}
