/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:48:53 by agigi             #+#    #+#             */
/*   Updated: 2021/06/26 14:47:48 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *message, int code_ex, int fd)
{
	ft_putstr_fd(message, fd);
	exit(code_ex);
}

int	(ft_check_argv(char *argv))
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[0] == '0' && ft_strlen(argv) > 1)
			return (0);
		if (!ft_isdigit(argv[i]))
		{
			if (i == 0 && argv[i] == '-' && ft_strlen(argv) > 1)
				;
			else
				return (0);
		}
		i++;
	}
	if ((ft_atoi(argv) == -1 && ft_strcmp(argv, "-1") && ft_strlen(argv) != 2) \
		|| (ft_atoi(argv) == 0 && ft_strcmp(argv, "0") && ft_strlen(argv) != 1))
		return (0);
	return (1);
}

int	ft_check_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j]) && \
			ft_strlen(argv[i]) == ft_strlen(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int ft_check_sort(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i + 1]) - ft_atoi(argv[i]) != 1)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		ft_exit("", 0, 1);
	while (argv[i])
	{
		if (!ft_check_argv(argv[i]))
			ft_exit("Error\n", 1, 2);
		i++;
	}
	if (!ft_check_sort(argc, argv))
		ft_exit("", 0, 1);
	if (!ft_check_duplicate(argv))
		ft_exit("Error\n", 1, 2);
	printf("start algos\n");
	return (0);
}
