/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:48:53 by agigi             #+#    #+#             */
/*   Updated: 2021/06/27 19:32:52 by agigi            ###   ########.fr       */
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

	i = 1;
	while (i < argc)
	{
		cell = ft_calloc(1, sizeof(t_cell));
		cell->value = ft_atoi(argv[i]);
		ft_lstadd_back(&data->stack_a, ft_lstnew(cell));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ft_check_input(argc, argv) == -1)
		ft_error_exit("Error\n");
	if (!ft_check_input(argc, argv))
		return (0);
	ft_init(&data, argc, argv);
	ft_add_order(&data);
	printf("start algos\n");
	return (0);
}
