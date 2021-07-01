/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:25:58 by agigi             #+#    #+#             */
/*   Updated: 2021/07/01 21:04:22 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_sort_array(int *array, int len)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j + i < len)
		{
			if (array[j + i] < array[i])
			{
				tmp = array[j + i];
				array[j + i] = array[i];
				array[i] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

static void	ft_add_sort_order(t_data *data, int *array, int len)
{
	int		i;
	t_list	*tmp;

	i = 0;
	array = ft_sort_array(array, len);
	tmp = data->stack_a;
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (((t_cell *)tmp->content)->value == array[i])
			{
				((t_cell *)tmp->content)->order = i + 1;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	ft_add_order(t_data *data)
{
	t_list	*tmp_list;
	int		*array;
	int		i;
	int		len;

	i = 0;
	tmp_list = data->stack_a;
	len = ft_lstsize(tmp_list);
	array = ft_calloc(len + 1, sizeof(int));
	while (tmp_list)
	{
		array[i] = ((t_cell *)tmp_list->content)->value;
		tmp_list = tmp_list->next;
		i++;
	}
	i = 0;
	ft_add_sort_order(data, array, len);
	free (array);
}
