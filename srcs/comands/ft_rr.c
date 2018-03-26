
#include "libswap.h"

static t_stack	*ft_rotate(t_stack *a)
{
	t_num *tmp;

	tmp = a->bgn->next;
	a->bgn->next = NULL;
	a->bgn->prev = a->end;
	a->end->next = a->bgn;
	a->end = a->bgn;
	a->bgn = tmp;
	a->bgn->prev = NULL;
	return (a);
}

t_stack		*ft_rr(t_stack *a, t_ret *ret)
{
	char *del;


	a = ft_rotate(a);
	a->s_b = ft_rotate(a->s_b);
	del = ret->tp;
	ret->tp = ft_strjoin(ret->tp, " rr");
	ret->mov += 1;
	return (a);
}
