/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:10:24 by igaliuk           #+#    #+#             */
/*   Updated: 2018/01/22 14:24:02 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct		s_list2
{
	int				d;
	struct s_list2	*next;
	struct s_list2	*prev;
}					t_list2;

typedef struct		s_stacks
{
	t_list2			*begin;
	t_list2			*end;
	t_list2			*tmp1;
	t_list2			*tmp2;
	size_t			len;
}					t_stacks;

typedef struct		s_v
{
	size_t			va;
	size_t			vb;
	int				ve;
	int				vk;
}					t_v;

typedef struct		s_fl
{
	int				fll;
	int				flv;
	int				l;
}					t_fl;

void				ft_zerostack(t_stacks *st);

void				ft_usa(int k);

int					ft_lstnew_ps(t_stacks *st);
void				ft_lstadd_ps(t_stacks *st);
void				ft_lstaddback_ps(t_stacks *st);
void				ft_lstdel_ps(t_stacks *st);
void				ft_lstlen_ps(t_stacks *st);

void				ft_error(t_stacks *a);
void				ft_readstacka(int argc, char **argv, t_stacks *a, t_fl *fl);
int					ft_atoi_ps(char *str, t_stacks *st);
void				ft_checkstacka(t_stacks *st);

int					ft_checkflags(int argc, char **argv, t_stacks *a, t_fl *fl);
void				ft_checkflagserr(int argc, char **argv, t_stacks *a);

void				ft_zeroflags(t_fl *fl);

void				ft_oper1_5(t_stacks *a, t_stacks *b, char *op);
void				ft_oper6_11(t_stacks *a, t_stacks *b, char *op);
void				ft_operations(t_stacks *a, t_stacks *b, t_fl *fl);

void				ft_ststatus(t_stacks *st);
void				ft_flags(t_stacks *a, t_stacks *b, t_fl *fl, int k);

void				ft_swap_s_ps(t_stacks *st);
void				ft_swap_p_ps(t_stacks *std, t_stacks *sts);
void				ft_swap_r_ps(t_stacks *st);
void				ft_swap_rr_ps(t_stacks *st);

int					ft_checksorta(t_stacks *a);
int					ft_checksortb(t_stacks *b);

int					ft_badsort(t_stacks *st, t_list **lst, int z);
int					ft_checkhalf(t_stacks *st, int z, int k);

int					ft_startsort(t_stacks *a, t_stacks *b, t_list **lst);

int					ft_reca(t_stacks *a, t_stacks *b, t_list **lst, t_v v);
t_v					ft_halfa(t_stacks *a, t_stacks *b, t_list **lst, t_v v);
t_v					ft_halfa1(t_stacks *a, t_stacks *b, t_list **lst, t_v v);
t_v					ft_halfa2(t_stacks *a, t_stacks *b, t_list **lst, t_v v);

int					ft_recb(t_stacks *a, t_stacks *b, t_list **lst, t_v v);
t_v					ft_halfb(t_stacks *a, t_stacks *b, t_list **lst, t_v v);
t_v					ft_halfb1(t_stacks *a, t_stacks *b, t_list **lst, t_v v);
t_v					ft_halfb2(t_stacks *a, t_stacks *b, t_list **lst, t_v v);

int					ft_sorta(t_stacks *a, t_stacks *b, t_list **lst, int k);
int					ft_sorta3(t_stacks *a, t_stacks *b, t_list **lst);
int					ft_sorta3_1(t_stacks *a, t_stacks *b, t_list **lst);
int					ft_sorta3_2(t_stacks *a, t_stacks *b, t_list **lst);
int					ft_casea(t_stacks *a, t_stacks *b, t_list **lst, int k);

int					ft_sortalast3_1(t_stacks *a, t_stacks *b, t_list **lst);
int					ft_sortalast3_2(t_stacks *a, t_stacks *b, t_list **lst);

int					ft_sortb(t_stacks *a, t_stacks *b, t_list **lst, int k);
int					ft_sortb3(t_stacks *a, t_stacks *b, t_list **lst);
int					ft_sortb3_1(t_stacks *a, t_stacks *b, t_list **lst);
int					ft_sortb3_2(t_stacks *a, t_stacks *b, t_list **lst);
int					ft_caseb(t_stacks *a, t_stacks *b, t_list **lst, int k);

int					ft_sortblast3_1(t_stacks *a, t_stacks *b, t_list **lst);
int					ft_sortblast3_2(t_stacks *a, t_stacks *b, t_list **lst);

int					ft_stepa(t_stacks *a, t_stacks *b, char **str, int k);
void				ft_stepa1(t_stacks *a, t_stacks *b, char **str);
void				ft_stepa2(t_stacks *a, t_stacks *b, char **str);
void				ft_stepa3(t_stacks *a, t_stacks *b, char **str);
void				ft_stepa4(t_stacks *a, t_stacks *b, char **str);

int					ft_stepb(t_stacks *a, t_stacks *b, char **str, int k);
void				ft_stepb1(t_stacks *a, t_stacks *b, char **str);
void				ft_stepb2(t_stacks *a, t_stacks *b, char **str);
void				ft_stepb3(t_stacks *a, t_stacks *b, char **str);
void				ft_stepb4(t_stacks *a, t_stacks *b, char **str);

void				ft_updatesort(t_list **lst);
void				ft_delorchg(t_list **lst, t_list **tmp, int i);
void				ft_upchg(t_list **lst, t_list **tmp);
int					ft_updel(t_list **lst, t_list **tmp);
void				ft_updelandchg(t_list **lst, t_list **tmp);

int					ft_lenlen(t_list **lst);
int					ft_tofin(t_list **lst);

#endif
