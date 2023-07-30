/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:45:44 by eclark            #+#    #+#             */
/*   Updated: 2023/07/30 17:45:46 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include <dirent.h>
# include "minishell.h"

void	change_path(t_tools *tools);
int		mini_echo(t_tools *tools, t_simple_cmds *simple_cmd);
int		mini_cd(t_tools *tools, t_simple_cmds *simple_cmd);
int		mini_pwd(t_tools *tools, t_simple_cmds *simple_cmd);
int		mini_export(t_tools *tools, t_simple_cmds *simple_cmd);
int		mini_unset(t_tools *tools, t_simple_cmds *simple_cmd);
int		mini_env(t_tools *tools, t_simple_cmds *simple_cmd);
int		mini_exit(t_tools *tools, t_simple_cmds *simple_cmd);
int		mini_continue(t_tools *tools, t_simple_cmds *simple_cmd);

size_t	equal_sign(char *str);
int		check_valid_identifier(char c);

#endif