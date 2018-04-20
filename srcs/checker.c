/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:51:21 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/20 19:51:19 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static int	ft_chkr_sort(t_stack *a)
{
	t_num *n;

	n = a->bgn;
	while(n->next)
	{
		if(n->num > n->next->num)
			return (-1);
		n = n->next;
	}
	if (a->s_b->bgn == NULL)
		return (1);
	return (-1);
}

static int	ft_checker(t_stack *a, char **ord)
{
	int i;
	t_ret *r;
	t_num *tmp;

	r = ft_ret_new(0);
	i = 0;
	while(ord[i])
	{
		if (ft_strcmp(ord[i], "sa") == 0 && a->bgn->next)
			ft_sa(a, r);
		else if (ft_strcmp(ord[i], "sb") == 0 && a->s_b->bgn->next)
			ft_sb(a->s_b, r);
		else if (ft_strcmp(ord[i], "ss") == 0 && a->bgn->next && a->s_b->bgn->next)
			ft_ss(a, r);
		else if (ft_strcmp(ord[i], "pa") == 0 && a->s_b->bgn)
			ft_pa(a, a->s_b, r);
		else if (ft_strcmp(ord[i], "pb") == 0 && a->bgn)
			ft_pb(a, a->s_b, r);
		else if (ft_strcmp(ord[i], "ra") == 0 && a->bgn->next)
			ft_ra(a, r);
		else if (ft_strcmp(ord[i], "rb") == 0 && a->s_b->bgn->next)
			ft_rb(a->s_b, r);
		else if (ft_strcmp(ord[i], "rr") == 0 && a->s_b->bgn->next && a->bgn->next)
			ft_rr(a, r);
		else if (ft_strcmp(ord[i], "rra") == 0 && a->bgn->next)
			ft_rra(a, r);
		else if (ft_strcmp(ord[i], "rrb") == 0 && a->s_b->bgn->next)
			ft_rrb(a->s_b, r);
		else if (ft_strcmp(ord[i], "rrr") == 0 && a->s_b->bgn->next && a->bgn->next)
			ft_rrr(a, r);
		else
			return (-1);
		i++;
		tmp = a->bgn;
	}
	if (ft_chkr_sort(a))
		return (1);
	return(-1);
}

static char	**get_orders(void)
{
	char	*ret;
	char	**dob;
	char	*d;
	int		i;
	char	*buf;

	i = 0;
	if (!(ret = ft_strnew(0)))
		return (NULL);
	if (!(buf = ft_strnew(5)))
		return (NULL);
	while(read(0, buf, 4))
	{
		d = ret;
		ret = ft_strjoin(ret, buf);
		ft_strdel(&d);
		buf = ft_memset(buf, 0, 5);
	}
	dob = ft_strsplit(ret, '\n');
	return (dob);
}

int		checker(t_num *n)
{
	char	**ord;
	t_stack	*a;

	if (!(a = ft_stacknew(n)))
		return (-1);
	if (!(ord = get_orders()))
		return (-1);
	if (ft_checker(a, ord) == 1)
		ft_putstr("OK");
	else
		ft_putstr("error");
	return (0);
}
