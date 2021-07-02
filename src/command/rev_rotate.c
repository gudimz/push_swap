/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:55:41 by agigi             #+#    #+#             */
/*   Updated: 2021/07/02 23:10:36 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate_a(t_data *data, int flag)
{
	t_cell	*prev;
	t_cell	*curr;
	t_list	*tmp;

	if (!(data->stack_a && data->stack_a->next))
		return ;
	tmp = data->stack_a;
	prev = (t_cell *)(ft_lstlast(tmp)->content);
	while (tmp)
	{
		curr = tmp->content;
		tmp->content = prev;
		prev = curr;
		tmp = tmp->next;
	}
	if (flag)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rev_rotate_b(t_data *data, int flag)
{
	t_cell	*prev;
	t_cell	*curr;
	t_list	*tmp;

	if (!(data->stack_b && data->stack_b->next))
		return ;
	tmp = data->stack_b;
	prev = (t_cell *)(ft_lstlast(tmp)->content);
	while (tmp)
	{
		curr = tmp->content;
		tmp->content = prev;
		prev = curr;
		tmp = tmp->next;
	}
	if (flag)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rev_rotate_ab(t_data *data, int flag)
{
	ft_rev_rotate_a(data, 0);
	ft_rev_rotate_b(data, 0);
	if (flag)
		ft_putstr_fd("rrr\n", 1);
}
