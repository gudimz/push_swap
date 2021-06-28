/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:48:53 by agigi             #+#    #+#             */
/*   Updated: 2021/06/28 19:49:17 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

static void	ft_init(t_data *data, int argc, char **argv)
{
	int		i;
	t_cell	*cell;
	t_list	*new;

	i = 1;
	while (i < argc)
	{
		cell = ft_calloc(1, sizeof(t_cell));
		if (!cell)
			ft_error_exit("Error\n");
		cell->value = ft_atoi(argv[i]);
		new = ft_lstnew(cell);
		if (!new)
			ft_error_exit("Error\n");
		ft_lstadd_back(&data->stack_a, new);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*tmp_a;
	t_list	*tmp_b;

	ft_bzero(&data, sizeof(t_data));
	if (ft_check_input(argc, argv) == -1)
		ft_error_exit("Error\n");
	if (!ft_check_input(argc, argv))
		return (0);
	ft_init(&data, argc, argv);
	ft_add_order(&data);
	printf("start algos\n");
	if (argc > 5)
		ft_big_sort_stack(&data);
	// else
	// 	ft_small_sort_stack(&data);
	tmp_a = data.stack_a;
	tmp_b = data.stack_b;
	while (tmp_a)
	{
		printf("A_val= %d\n", ((t_cell *)tmp_a->content)->value);
		// printf("A_ord= %d\n", ((t_cell *)tmp_a->content)->order);
		tmp_a = tmp_a->next;
	}
	while (tmp_b)
	{
		printf("B_val= %d\n", ((t_cell *)tmp_b->content)->value);
		// printf("B_ord= %d\n", ((t_cell *)tmp_b->content)->order);
		tmp_b = tmp_b->next;
	}
	return (0);
}
