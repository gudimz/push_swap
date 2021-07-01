/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:59:23 by agigi             #+#    #+#             */
/*   Updated: 2021/07/01 12:53:57 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_groupsize(t_data *data, char name)
{
	int size;
	int flag;
	t_list	*tmp;

	if (name == 'a')
		tmp = data->stack_a;
	else
		tmp = data->stack_b;
	size = 0;
	flag = ((t_cell *)tmp->content)->group;
	while (tmp && flag == ((t_cell *)tmp->content)->group)
	{
		tmp = tmp->next;
		size++;
	}
	data->group.min = data->next;
	data->group.max = size + (data->group.min - 1);
	if (size <= 5)
		data->group.med = (data->group.max - data->group.min) / 2 + data->group.min;
	else
		data->group.med = (data->group.max - data->group.min) / 3 * 2 + data->group.min;
	return (size);
}
void	ft_from_a_to_b(t_data	*data)
{
	int i;
	int	count_ra;
	int	index_gr;
	int	last_gr;
	int	count_to_b;

	count_ra = 0;
	index_gr = ((t_cell *)data->stack_a->content)->group;
	if (index_gr >= 0)
	{
		i = ft_groupsize(data, 'a');
		count_to_b = data->group.med - data->group.min + 1;
		last_gr = ((t_cell *)ft_lstlast(data->stack_a)->content)->group;
		// printf ("count = %d\n\n", count_to_b);
		// printf ("i = %d\n\n", count_to_b);
		while (count_to_b && i--)
		{
			if (((t_cell *)data->stack_a->content)->order == data->next && \
														((t_cell *)ft_lstlast(data->stack_a)->content)->group == -1)
			{
				((t_cell *)data->stack_a->content)->group = -1;
				data->next++;
				ft_rotate_a(data, 1);
			}
			else if (((t_cell *)data->stack_a->content)->order > data->group.med)
			{
				ft_rotate_a(data, 1);
				count_ra++;
			}
			else
			{
				ft_push_b(data);
				count_to_b--;
			}
		}
		if (index_gr != last_gr)
		{
			while (count_ra--)
				ft_rev_rotate_a(data, 1);
		}
	}
}

void	ft_from_b_to_a(t_data *data)
{
	int i;
	int	count_to_a;

	i = ft_groupsize(data, 'b');
	count_to_a = data->group.max - data->group.med + 1;
	data->group.index++;
	while (count_to_a && data->stack_b && i--)
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
			count_to_a--;
			ft_push_a(data);
		}
		else
			ft_rotate_b(data, 1);
	}
}

// void	ft_first_sort(t_data *data)
// {
// 	int	i;
// 	int	size;

// 	i = 0;
// 	size = ft_lstsize(data->stack_a);
// 	while (i < size)
// 	{
// 		if (((t_cell *)data->stack_a->content)->order <= data->group.med)
// 			ft_push_b(data);
// 		else
// 			ft_rotate_a(data, 1);
// 		i++;
// 	}
// }

void	ft_big_sort_stack(t_data *data)
{
	ft_from_a_to_b(data);
	while (data->stack_b)
		ft_from_b_to_a(data);
}