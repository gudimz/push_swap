/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:48:53 by agigi             #+#    #+#             */
/*   Updated: 2021/07/03 00:12:50 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(t_data *data)
{
	if (data->stack_a)
		ft_lstclear(&data->stack_a, free);
	if (data->stack_b)
		ft_lstclear(&data->stack_b, free);
}

static void	ft_error_exit(t_data *data, char *message, int flag)
{
	ft_putstr_fd(message, 2);
	if (flag)
		ft_free(data);
	exit(1);
}

static void	ft_init(t_data *data, int argc, char **argv)
{
	int		i;
	t_cell	*cell;
	t_list	*new;

	i = 1;
	data->group.min = 1;
	data->group.max = argc - 1;
	data->group.med = (data->group.max - data->group.min) / 2 + data->group.min;
	data->next = 1;
	while (i < argc)
	{
		cell = ft_calloc(1, sizeof(t_cell));
		if (!cell)
			ft_error_exit(data, "Error\n", 1);
		cell->value = ft_atoi(argv[i]);
		new = ft_lstnew(cell);
		if (!new)
			ft_error_exit(data, "Error\n", 1);
		ft_lstadd_back(&data->stack_a, new);
		i++;
	}
}

int	ft_check_sort_stack_a(t_data *data)
{
	t_list	*tmp;

	tmp = data->stack_a;
	if (((t_cell *)tmp->content)->group != -1 || data->stack_b)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		size;

	ft_bzero(&data, sizeof(t_data));
	if (ft_check_input(argc, argv) == -1)
		ft_error_exit(&data, "Error\n", 0);
	if (!ft_check_input(argc, argv))
		return (0);
	ft_init(&data, argc, argv);
	ft_add_order(&data);
	size = ft_lstsize(data.stack_a);
	if (size > 5)
	{
		while (!ft_check_sort_stack_a(&data))
			ft_big_sort_stack(&data);
	}
	else
		ft_small_sort_stack(&data);
	ft_free(&data);
	return (0);
}
