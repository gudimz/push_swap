/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:38:59 by agigi             #+#    #+#             */
/*   Updated: 2021/06/28 00:37:18 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push_a(t_data *data)
{
	t_list *tmp;

	tmp = data->stack_b;
	if (!data->stack_b)
		return ;
	ft_lstadd_front(&data->stack_a, ft_lstnew(data->stack_b->content));
	data->stack_b = data->stack_b->next;
	free(tmp);
}

void ft_push_b(t_data *data)
{
	t_list *tmp;

	tmp = data->stack_a;
	if (!data->stack_a)
		return ;
	ft_lstadd_front(&data->stack_b, ft_lstnew(data->stack_a->content));
	data->stack_a = data->stack_a->next;
	free(tmp);
}
