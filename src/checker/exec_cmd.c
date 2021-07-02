/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:53:02 by agigi             #+#    #+#             */
/*   Updated: 2021/07/03 00:14:35 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_valid_cmd(char *cmd)
{
	if (!ft_strcmp(cmd, "sa") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "sb") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "ss") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "pa") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "pb") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "ra") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "rb") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "rr") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "rra") && ft_strlen(cmd) == 3)
		return (1);
	else if (!ft_strcmp(cmd, "rrb") && ft_strlen(cmd) == 3)
		return (1);
	else if (!ft_strcmp(cmd, "rrr") && ft_strlen(cmd) == 3)
		return (1);
	return (0);
}

void	ft_exec_cmd(t_data *data, char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		ft_swap_a(data, 0);
	else if (!ft_strcmp(cmd, "sb"))
		ft_swap_b(data, 0);
	else if (!ft_strcmp(cmd, "ss"))
		ft_swap_ab(data, 0);
	else if (!ft_strcmp(cmd, "pa"))
		ft_push_a(data, 0);
	else if (!ft_strcmp(cmd, "pb"))
		ft_push_b(data, 0);
	else if (!ft_strcmp(cmd, "ra"))
		ft_rotate_a(data, 0);
	else if (!ft_strcmp(cmd, "rb"))
		ft_rotate_b(data, 0);
	else if (!ft_strcmp(cmd, "rr"))
		ft_rotate_ab(data, 0);
	else if (!ft_strcmp(cmd, "rra"))
		ft_rev_rotate_a(data, 0);
	else if (!ft_strcmp(cmd, "rrb"))
		ft_rev_rotate_b(data, 0);
	else if (!ft_strcmp(cmd, "rrr"))
		ft_rev_rotate_ab(data, 0);
	free(cmd);
}
