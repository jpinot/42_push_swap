
#include "libswap.h"

static t_stack	*swap(t_stack *a)
{
	t_num *tmp;

	 tmp = a->bgn->next;
	 a->bgn->next = NULL;
	 a->bgn->prev = a->end;
	 a->end->next = a->bgn;
	 a->end = a->bgn;
	 a->bgn = tmp;
	return (a);
}

t_stack		*ft_ss(t_stack *s_a, t_ret ret)
{
	char *del;

	s_a = swap(s_a);
	s_a->s_b = swap(s_a->s_b);
	del = ret.tp;
	ret.tp = ft_strjoin(ret.tp, " ss");
	ret.mov += 1;
	ft_strdel(&del);
	return (s_a);
}
