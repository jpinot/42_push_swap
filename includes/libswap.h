/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libswap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:15:07 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/13 09:45:59 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSWAP_H
# define LIBSWAP_H
# include "../libft/libft.h"

typedef struct	s_num
{
	int				num;
	int				g;
	int				p;
	struct s_num	*next;
	struct s_num	*prev;
}				t_num;

typedef struct	s_stack
{
	t_num			*bgn;
	t_num			*end;
	t_num			*scnd;
//	t_num			*ref;
	struct s_stack	*s_b;
}				t_stack;

t_num		*ft_sort(t_num *num);
t_num		*ft_lstnew_num(int num, t_num *p);
int			push_swap(t_num *bgn);
t_stack		*ft_stacknew(t_num *n);
#endif
