/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:14:07 by agigi             #+#    #+#             */
/*   Updated: 2021/06/29 18:52:40 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack_b(t_data *data)
{
	int i;
	int	size;

	i = 0;
	size = ft_lstsize(data->stack_b);
	while (i < size)
	{
		if (((t_cell *)data->stack_b->content)->order > data->group_b.med)
		{
			((t_cell *)data->stack_b->content)->flag = data->flag;
			ft_push_a(data);
		}
		else
		{
			if (((t_cell *)data->stack_b->content)->order == data->next)
			{
				ft_push_a(data);
				ft_rotate_a(data, 1);
				data->next++;
			}
			else
				ft_rotate_b(data, 1);
		}
		i++;
	}
}

void	ft_check_stack_a(t_data *data)
{
	int flag;

	if (((t_cell *)data->stack_a->content)->flag != 0)
	{
		flag = ((t_cell *)data->stack_a->content)->flag;
		while (flag == ((t_cell *)data->stack_a->content)->flag)
		{
			if (((t_cell *)data->stack_a->content)->order == data->next)
			{
				ft_rotate_a(data, 1);
				data->next++;
			}
			else
				ft_push_b(data);
		}
	}
}

void	ft_check_stack_b(t_data *data)
{
	t_list	*tmp;

	data->group_b.max = data->group_a.med;
	data->group_b.med = (data->group_b.max - data->next) / 2 + data->next;
	data->flag++;
	ft_sort_stack_b(data);
	if (ft_lstsize(data->stack_b) > 0)
	{
		ft_check_stack_b(data);
		data->flag++;
	}
	ft_check_stack_a(data);
	if (ft_lstsize(data->stack_b) > 0)
	{
		tmp = data->stack_b;
		data->group_a.med = 0;
		while (tmp)
		{
		if (((t_cell *)tmp->content)->order > data->group_a.med)
			data->group_a.med = ((t_cell *)tmp->content)->order;
		tmp = tmp->next;
		}
		ft_check_stack_b(data);
	}
}

void	ft_sort_half_a(t_data *data)
{
	data->group_a.max = ft_lstsize(data->stack_a);
	data->group_a.med = data->group_a.max / 2 + data->next;
	while (((t_cell *)data->stack_a->content)->order != 1)
	{
		if (((t_cell *)data->stack_a->content)->order <= data->group_a.med)
			ft_push_b(data);
		else
			ft_rotate_a(data, 1);
	}
	ft_check_stack_b(data);
}

void	ft_big_sort_stack(t_data *data)
{
	int	i;

	i = 0;
	data->group_a.min = 1;
	data->next = 1;
	data->group_a.max = ft_lstsize(data->stack_a);
	data->group_a.med = data->group_a.max / 2 + data->next;
	while (i < data->group_a.max)
	{
		if (((t_cell *)data->stack_a->content)->order <= data->group_a.med)
			ft_push_b(data);
		else
			ft_rotate_a(data, 1);
		i++;
	}
	ft_check_stack_b(data);
}
