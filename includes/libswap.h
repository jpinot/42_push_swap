/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libswap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:15:07 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/28 15:36:09 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSWAP_H
# define LIBSWAP_H
# include "../libft/libft.h"
//# include "../libft/ft_printf/includes/libprintf.h"

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
	int				mov;
	int				sort;
	char			*tp;
	struct s_ret	*next;
}				t_ret;

typedef struct	s_flag
{
	int	v;
	int	o;
	int	l;
	int	p;
	int	m;
	int	s;
}		t_flag;

//PS

int	push_swap(t_num *bgn);
int	checker(t_num *n, t_flag);

//CHEKER

void   	ft_print_stack(t_stack *stk);
void    ft_print_stack_c(t_stack *stk, char **str, int i, int p);
void    ft_color_impl(t_stack *a, char **str, int i);
void    ft_color_del(t_stack *a, char **str, int i);
int	ft_chk_corr_ord(char **ord, int i);
void    ft_read_nd_clear(void);

//STRUCT

void		ft_del_num(t_num **l);
void		ft_del_ret(t_ret **lst);
void		ft_del_stack(t_stack **lst);
t_num		*ft_sort(t_num *num);
t_num		*ft_lstnew_num(int num, t_num *p);
t_ret		*ft_ret_new(int sort);
t_stack		*ft_stacknew(t_num *n);
int			ft_atoi_ps(const char *str);

//BUBBLE

int			ft_check_side(t_stack *s, int pos);	
int			ft_check_side_g(t_stack *s, int g);
int			ft_check_state(t_stack *s_a);
t_stack		*ft_group_one_sort(t_stack *a, t_ret *ret);
t_stack		*ft_group_sort(t_stack *a, t_stack *b, t_ret *ret);
int			ft_chk_sort(t_stack *a);

//MERGE

t_stack	*ft_sort_top_a(t_stack *a, t_ret *ret, int pos);
t_stack	*ft_sort_top_b(t_stack *a, t_stack *b, t_ret *ret, int m);
t_stack	*ft_sort_g_top_a(t_stack *a, t_ret *ret, int pos);
t_stack	*ft_sort_g_top_b(t_stack *a, t_stack *b, t_ret *ret, int pos);
int		ft_check_m(t_stack *a);
int		ft_non_minor_pos(t_stack *a, int pos);
int		ft_non_major_pos(t_stack *a, int pos);
int		ft_check_pos(t_num *a, int p);

int     ft_is_sort(t_stack *a, int p);
int ft_merge_a(t_stack *a, t_ret *ret, int p);
int ft_merge_a_bgn(t_stack *a, t_ret *ret, int p);
int ft_merge_b(t_stack *a, t_ret *ret, int p);

//SORRT ALG

t_ret	*ft_bubble_one(t_num *bgn);
t_ret	*ft_bubble_group(t_num *bgn);
t_ret   *ft_merge_one(t_num *bgn);

//CMNDS

t_stack		*ft_rrb(t_stack *b, t_ret *ret);
t_stack		*ft_rra(t_stack *a, t_ret *ret);
t_stack		*ft_ra(t_stack *a, t_ret *ret);
t_stack		*ft_rb(t_stack *b, t_ret *ret);
t_stack		*ft_pa(t_stack *a, t_stack *b, t_ret *ret);
t_stack		*ft_pb(t_stack *a, t_stack *b, t_ret *ret);
t_stack		*ft_sa(t_stack *a, t_ret *res);
t_stack		*ft_sb(t_stack *b, t_ret *res);
t_stack		*ft_ss(t_stack *a, t_ret *ret);
t_stack		*ft_rr(t_stack *a, t_ret *ret);
t_stack		*ft_rrr(t_stack *a, t_ret *ret);
#endif
