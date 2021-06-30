/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:59:23 by agigi             #+#    #+#             */
/*   Updated: 2021/06/30 20:05:16 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_from_a_to_b(t_data	*data)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(data->stack_a);
	while (i < size)
	{
		if (((t_cell *)data->stack_a->content)->order <= data->group.med)
			ft_push_b(data);
		else
			ft_rotate_a(data, 1);
		i++;
	}
}

void	ft_from_b_to_a(t_data *data)
{
	int i;

	i = 0;
	data->group.min = data->next;
	data->group.max = data->group.med + (data->group.min - 1);
	data->group.med = (data->group.max - data->group.min) / 2 + data->group.min;
	data->group.index++;
	while (data->stack_b && i < data->group.max)
	{
		if (((t_cell *)data->stack_b->content)->order == data->next)
		{
			((t_cell *)data->stack_b->content)->group = -1;
			data->next++;
			ft_push_a(data);
			ft_rotate_a(data, 1);
		}
		else if (((t_cell *)data->stack_b->content)->order >=  data->group.med)
		{
			((t_cell *)data->stack_b->content)->group = data->group.index;
			ft_push_a(data);
		}
		else
			ft_rotate_b(data, 1);
		i++;
	}
}

void	ft_big_sort_stack(t_data *data)
{
	ft_from_a_to_b(data);
	while (data->stack_b)
		ft_from_b_to_a(data);
}