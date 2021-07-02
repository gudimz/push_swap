/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:09:42 by agigi             #+#    #+#             */
/*   Updated: 2021/07/03 00:59:35 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_check_argv(char *argv)
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

static int	ft_check_duplicate(char **argv)
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

int	ft_check_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_check_argv(argv[i]))
			return (0);
		i++;
	}
	if (!ft_check_duplicate(argv))
		return (0);
	return (1);
}
