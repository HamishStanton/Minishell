/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:46:48 by hstanton          #+#    #+#             */
/*   Updated: 2023/07/30 17:42:31 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	mini_pwd(t_tools *tools, t_simple_cmds *simple_cmd)
{
	(void) simple_cmd;
	ft_putendl_fd(tools->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
