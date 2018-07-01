/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:51:17 by jpinyot           #+#    #+#             */
/*   Updated: 2018/05/26 15:56:20 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_num	*ft_copynum(t_num *n)
{
	t_num *num;
	t_num *bgn;
	t_num *s;

	s = n;
	if ((num = ft_lstnew_num(s->num, NULL)) == NULL)
		return (NULL);
	bgn = num;
	while (s->next)
	{
		if ((num->next = ft_lstnew_num(s->next->num, num)) == NULL)
			return (NULL);
		num = num->next;
		s = s->next;
	}
	return (bgn);
}

static int		ft_compare_ord(char **ord, int i)
{
	if (!ord[i + 1])
		return (1);
	if (ft_strcmp(ord[i], "sa") == 0 && ft_strcmp(ord[i + 1], "sb") == 0)
		return (write(1, "ss", 2));
	else if (ft_strcmp(ord[i], "ra") == 0 && ft_strcmp(ord[i + 1], "rb") == 0)
		return (write(1, "rr", 2));
	else if (ft_strcmp(ord[i], "rra") == 0 && ft_strcmp(ord[i + 1], "rrb") == 0)
		return (write(1, "rrr", 2));
	if (ft_strcmp(ord[i], "sb") == 0 && ft_strcmp(ord[i + 1], "sa") == 0)
		return (write(1, "ss", 2));
	else if (ft_strcmp(ord[i], "rb") == 0 && ft_strcmp(ord[i + 1], "ra") == 0)
		return (write(1, "rr", 2));
	else if (ft_strcmp(ord[i], "rrb") == 0 && ft_strcmp(ord[i + 1], "rra") == 0)
		return (write(1, "rrr", 2));
	return (1);
}

static int		ft_putstr_ps(char *s)
{
	char	**t;
	int		i;

	i = 0;
	if (!(t = ft_strsplit(s, '\n')))
		return (-1);
	while (t[i])
	{
		if (ft_compare_ord(t, i) == 1)
			ft_putstr(t[i]);
		else
			i++;
		ft_putchar('\n');
		i++;
	}
	i = -1;
	while (t[++i])
		free(t[i]);
	free(t);
	return (0);
}

static int		ft_print_res(t_ret *op)
{
	if (op->mov <= op->next->mov && op->mov <= op->next->next->mov)
	{
		if (ft_putstr_ps(&(op->tp[4])) == -1)
			return (-1);
	}
	else if (op->mov > op->next->mov && op->next->mov <= op->next->next->mov)
	{
		if (ft_putstr_ps(&(op->next->tp[4])) == -1)
			return (-1);
	}
	else if (op->mov > op->next->next->mov &&
			op->next->mov > op->next->next->mov)
	{
		if (ft_putstr_ps(&(op->next->next->tp[4])) == -1)
			return (-1);
	}
	return (0);
}

int				push_swap(t_num *bgn)
{
	t_ret	*op;
	t_num	*n2;
	t_num	*n3;

	if (!(n2 = ft_copynum(bgn)))
		return (-1);
	if (!(n3 = ft_copynum(bgn)))
		return (-1);
	if (!(op = ft_bubble_one(bgn)))
		return (-1);
	if (!(op->next = ft_bubble_group(n2)))
		return (-1);
	if (!(op->next->next = ft_merge_one(n3)))
		return (-1);
	if (ft_print_res(op) == -1)
		return (-1);
	ft_del_ret(&op);
	return (0);
}
