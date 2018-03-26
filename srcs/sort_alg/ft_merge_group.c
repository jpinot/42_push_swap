
#include "libswap.h"

static int ft_check_g(t_stack *a, int g)
{
	t_num	*tmp;
	int	cnt;
	int	rtrn;
	int	ref;

	tmp = a->bgn;
	cnt = 0;
	rtrn = 0;
	ref = tmp->m;
	while (tmp)
	{
		cnt++;
		if (cnt == 3)
		{
			cnt = 0;
			rtrn++;
		}
		if (tmp->m != ref)
			return(rtrn);
		tmp = tmp->next;
	}
	return (rtrn);
}

static int	ft_is_sort_group(t_stack *a, int g)
{
	t_num	*tmp;

	tmp = a->bgn;
	if (g != a->l_g - 1)
	{
		while (tmp->next->g != a->l_g - 1)
		{
			if (tmp->pos != (tmp->next->pos - 1))
				return (0);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp->next)
		{
			if (tmp->pos != (tmp->next->pos - 1))
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

static int	ft_merge_a(t_stack *a, t_ret *ret, int g)
{
	int grp;
	int i;

	if (ft_check_g(a, g) <= 1 && !(ft_is_sort_group(a, (g))))
	{
		a = ft_sort_g_top_a(a, ret, g);
		return (a->bgn->g - 1);
	}
	write(1, "%", 1);
	grp = (g + 1) - (ft_check_g(a, g) / 2);
	write(1,"(", 1);
	ft_putnbr(grp);
	write(1,")", 1);
	if (a->s_b->bgn)
		i = a->s_b->bgn->m + 1;
	else
		i = 0;
	while (a->bgn->next != NULL)
	{
		if (ft_is_sort_group(a, g))
			break;
		if (ft_non_minor_pos(a, grp * 3))
		{
			if (a->end->m != -1)
				while(a->end->m != -1)
					ft_rra(a, ret);
			return (ft_merge_a(a, ret, g));
		}
		if (a->bgn->g >= grp)
			ft_ra(a, ret);
		else
		{
			a->bgn->m = i;
			ft_pb(a, a->s_b, ret);
		}
	}
	a->bgn->m = -1;
	if (a->end->m != -1)
	{
		while(a->end->m != -1)
			ft_rra(a, ret);
		return (ft_merge_a(a, ret, g));
	}
	return (a->bgn->g - 1);
}

static int	ft_merge_b(t_stack *a, t_ret *ret, int g)
{
	int grp;
	int m;
	int i;

	m = a->s_b->bgn->m;
	if ((i = (ft_check_g(a->s_b, g))) <= 1)
	{
	write(1, "&", 1);
		a = ft_sort_g_top_b(a, a->s_b, ret, g);
		g = a->bgn->g;
	}
	else
	{
		grp = (g + 1) - (i / 2);
		while (!(ft_non_major_pos(a->s_b, g * 3)))
		{
			if (a->s_b->bgn->g < g)
				ft_rb(a->s_b, ret);
			else
				ft_pa(a, a->s_b, ret);
		}
		if (a->s_b->end->m != 0)
			while (a->s_b->end->m == m)
				ft_rrb(a->s_b, ret);
	}
	return (g);
}

t_ret	*ft_merge_group(t_num *bgn)
{
	int		g;
	t_ret	*ret;
	t_stack	*a;

	ret = ft_ret_new(3);
	a = ft_stacknew(bgn);
	g = a->l_g -1;
	g = ft_merge_a(a, ret, g);
/*	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	ft_putnbr(g);
	write(1, ">", 1);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	ft_putnbr(g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
	g = ft_merge_a(a, ret, g);
	g = ft_merge_b(a, ret, g);
*/	
	while (a->s_b->bgn)
	{
		write(1, "%", 1);
		if(a->bgn && a->s_b->bgn)
			g = ft_merge_b(a, ret, g);
		if(a->bgn && a->s_b->bgn)
			g = ft_merge_a(a, ret, g);
	}
//	ft_putstr(ret->tp);
//	write(1, "\n", 1);
//	ft_putnbr(ret->mov);
//	a = ft_sa(a, res);
//	write(1, "$", 1);
//	ft_group_sort(a, a->s_b, res);
//	while (p < a->l - 1)
//	{
//		ft_pa(a, a->s_b, res);
//		p++;
//	}
	while (a->s_b->bgn)
	{
		write(1, "\n", 1);
		ft_putnbr(a->s_b->bgn->num);
		write(1, " ", 1);
		ft_putnbr(a->s_b->bgn->pos);
		write(1, " ", 1);
		ft_putnbr(a->s_b->bgn->g);
		write(1, " ", 1);
		ft_putnbr(a->s_b->bgn->m);
		a->s_b->bgn = a->s_b->bgn->next;
	}
		write(1, "\n", 1);
		write(1, "----------", 10);
		write(1, "\n", 1);
	while (a->bgn)
	{
		write(1, "\n", 1);
		ft_putnbr(a->bgn->num);
		write(1, " ", 1);
		ft_putnbr(a->bgn->pos);
		write(1, " ", 1);
		ft_putnbr(a->bgn->g);
//		write(1, " ", 1);
//		ft_putnbr(a->bgn->m);
		a->bgn = a->bgn->next;
	}
//	write(1, "\n", 1);
//	ft_putstr(res.tp);
	return (ret);
}
