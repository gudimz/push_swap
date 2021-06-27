/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:38:59 by agigi             #+#    #+#             */
/*   Updated: 2021/06/27 20:01:58 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push_a(t_data *data)
{
	if (!data->stack_b)
		return ;
	ft_lstadd_front(&data->stack_a, data->stack_b);
}

void ft_push_b(t_data *data)
{
	if (!data->stack_a)
		return ;
	ft_lstadd_front(&data->stack_b, data->stack_a);
}
