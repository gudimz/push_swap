/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:38:59 by agigi             #+#    #+#             */
/*   Updated: 2021/07/02 23:10:13 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_data *data, int flag)
{
	t_list	*tmp;

	if (!data->stack_b)
		return ;
	tmp = data->stack_b;
	data->stack_b = data->stack_b->next;
	ft_lstadd_front(&data->stack_a, tmp);
	if (flag)
		ft_putstr_fd("pa\n", 1);
}

void	ft_push_b(t_data *data, int flag)
{
	t_list	*tmp;

	if (!data->stack_a)
		return ;
	tmp = data->stack_a;
	data->stack_a = data->stack_a->next;
	tmp->next = 0;
	ft_lstadd_front(&data->stack_b, tmp);
	if (flag)
		ft_putstr_fd("pb\n", 1);
}
