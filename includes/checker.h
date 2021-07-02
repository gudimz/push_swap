/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:01:19 by agigi             #+#    #+#             */
/*   Updated: 2021/07/03 01:00:21 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_cell
{
	int	value;
}	t_cell;

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_cell	cell;
}	t_data;

int		ft_check_input(char **argv);
int		ft_valid_cmd(char *cmd);
void	ft_exec_cmd(t_data *data, char *cmd);
void	ft_push_a(t_data *data, int flag);
void	ft_push_b(t_data *data, int flag);
void	ft_swap_a(t_data *data, int flag);
void	ft_swap_b(t_data *data, int flag);
void	ft_swap_ab(t_data *data, int flag);
void	ft_rotate_a(t_data *data, int flag);
void	ft_rotate_b(t_data *data, int flag);
void	ft_rotate_ab(t_data *data, int flag);
void	ft_rev_rotate_a(t_data *data, int flag);
void	ft_rev_rotate_b(t_data *data, int flag);
void	ft_rev_rotate_ab(t_data *data, int flag);

#endif
