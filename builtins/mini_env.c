/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:47:02 by hstanton          #+#    #+#             */
/*   Updated: 2023/07/30 17:50:23 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	mini_env(t_tools *tools, t_simple_cmds *simple_cmd)
{
	int	i;

	(void) simple_cmd;
	i = 0;
	while (tools->envp[i])
	{
		ft_putendl_fd(tools->evp[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
