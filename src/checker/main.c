/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:05:21 by agigi             #+#    #+#             */
/*   Updated: 2021/07/03 00:34:03 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_free(t_data *data, char *cmd)
{
	if (data->stack_a)
		ft_lstclear(&data->stack_a, free);
	if (data->stack_b)
		ft_lstclear(&data->stack_b, free);
	if (cmd)
		free(cmd);
}

static void	ft_error_exit(t_data *data, char *cmd, char *message, int flag)
{
	ft_putstr_fd(message, 2);
	if (flag)
		ft_free(data, cmd);
	exit(1);
}

int	ft_check_sort(t_data *data)
{
	int		size;
	int		i;
	t_list	*tmp;

	i = 0;
	size = ft_lstsize(data->stack_b);
	if (size != 0)
		return (0);
	size = ft_lstsize(data->stack_a);
	tmp = data->stack_a;
	while (i < size - 1)
	{
		if (((t_cell *)tmp->next->content)->value < \
								((t_cell *)tmp->content)->value)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

static int	ft_init(t_data *data, int argc, char **argv)
{
	int		i;
	t_cell	*cell;
	t_list	*new;

	i = 1;
	while (i < argc)
	{
		cell = ft_calloc(1, sizeof(t_cell));
		if (!cell)
			return (0);
		cell->value = ft_atoi(argv[i]);
		new = ft_lstnew(cell);
		if (!new)
			return (0);
		ft_lstadd_back(&data->stack_a, new);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*cmd;

	cmd = NULL;
	if (argc == 1)
		return (0);
	ft_bzero(&data, sizeof(t_data));
	if (!ft_check_input(argv))
		ft_error_exit(&data, cmd, "Error\n", 0);
	if (!ft_init(&data, argc, argv))
		ft_error_exit(&data, cmd, "Error\n", 1);
	while (get_next_line(0, &cmd) > 0)
	{
		if (ft_valid_cmd(cmd))
			ft_exec_cmd(&data, cmd);
		else
			ft_error_exit(&data, cmd, "Error\n", 1);
	}
	if (ft_check_sort(&data))
		ft_putendl_fd("\033[1;32mOK\033[0m", 1);
	else
		ft_putendl_fd("\033[1;31mKO\033[0m", 1);
	ft_free(&data, cmd);
	return (0);
}
