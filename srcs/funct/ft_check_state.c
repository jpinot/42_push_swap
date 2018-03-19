
#include "libswap.h"

int	ft_check_state(t_stack *s_a)
{
	t_num	tmp;

	tmp = s_a->bgn;
	while (tmp->next != NULL)
	{
		if (tmp->pos < tmp->next->pos)
			return (1);
		tmp = tmp->next;
	}
	return (-1);
}
