/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:21:23 by agigi             #+#    #+#             */
/*   Updated: 2021/06/28 16:09:30 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_data *data)
{
	t_cell	*tmp;

	if (!(data->stack_a && data->stack_a->next))
		return ;
	tmp = (t_cell *)data->stack_a->content;
	data->stack_a->content = data->stack_a->next->content;
	data->stack_a->next->content = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	ft_swap_b(t_data *data)
{
	t_cell	*tmp;

	if (!(data->stack_b && data->stack_b->next))
		return ;
	tmp = (t_cell *)data->stack_b->content;
	data->stack_b->content = data->stack_b->next->content;
	data->stack_b->next->content = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ft_swap_ab(t_data *data)
{
	ft_swap_a(data);
	ft_swap_b(data);
	ft_putstr_fd("ss\n", 1);
}
