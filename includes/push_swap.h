/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:33:44 by agigi             #+#    #+#             */
/*   Updated: 2021/06/26 17:00:01 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# include <stdio.h> //delete before push!!!!!!

typedef struct	s_cell
{
		int value;
		int	order;
		int flag;
}				t_cell;
typedef struct	s_data
{
		t_list	*stack_a;
		t_list	*stack_b;
		t_cell	cell;
}				t_data;

int ft_check_input(int argc, char **argv);

#endif
