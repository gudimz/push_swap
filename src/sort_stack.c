/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:14:07 by agigi             #+#    #+#             */
/*   Updated: 2021/06/28 20:14:23 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack_b(t_data *data)
{
	data->group.max = data->group.med;
	data->group.med = (data->group.max - data->group.min) / 2 + data->group.min;
	data->flag++;
}

void	ft_big_sort_stack(t_data *data)
{
	int	i;

	i = 0;
	data->group.min = 1;
	data->group.max = ft_lstsize(data->stack_a);
	data->group.med = data->group.max / 2 + data->group.min;
	while (i < data->group.max)
	{
		if (((t_cell *)data->stack_a->content)->order <= data->group.med)
			ft_push_b(data);
		else
			ft_rotate_a(data, 1);
		i++;
	}
	ft_sort_stack_b(data);
}
