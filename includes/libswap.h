/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libswap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:15:07 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/23 14:45:55 by jpinyot          ###   ########.fr       */
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
	int				pos;
	int				m;
	struct s_num	*next;
	struct s_num	*prev;
}				t_num;

typedef struct	s_stack
{
	int			l;
	int				l_g;
	t_num			*bgn;
	t_num			*end;
	struct s_stack	*s_b;
}				t_stack;

typedef struct	s_ret
{
	int		mov;
	int		sort;
	char		*tp;
}			t_ret;

t_num		*ft_sort(t_num *num);
t_num		*ft_lstnew_num(int num, t_num *p);
int			push_swap(t_num *bgn);
t_stack		*ft_stacknew(t_num *n);
int			ft_check_side(t_stack *s, int pos);	
int			ft_check_side_g(t_stack *s, int g);
int			ft_check_state(t_stack *s_a);

t_stack *ft_group_one_sort(t_stack *a, t_ret ret);
t_stack *ft_group_sort(t_stack *a, t_stack *b, t_ret ret);


t_stack *ft_sort_top(t_stack *a, t_stack *b, t_ret ret, int m);
int  ft_check_m(t_stack *a);

t_ret	ft_bubble_one(t_num *bgn);
t_ret	ft_bubble_group(t_num *bgn);
t_ret   ft_merge_one(t_num *bgn);

t_stack         *ft_rrb(t_stack *b, t_ret ret);
t_stack         *ft_rra(t_stack *a, t_ret ret);
t_stack         *ft_ra(t_stack *a, t_ret ret);
t_stack         *ft_rb(t_stack *b, t_ret ret);
t_stack		*ft_pa(t_stack *a, t_stack *b, t_ret ret);
t_stack		*ft_pb(t_stack *a, t_stack *b, t_ret ret);
t_stack		*ft_sa(t_stack *a, t_ret res);
t_stack		*ft_sb(t_stack *b, t_ret res);
#endif
