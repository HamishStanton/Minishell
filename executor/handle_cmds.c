/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:39:26 by eclark            #+#    #+#             */
/*   Updated: 2023/07/30 17:43:04 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*F_OK checking whether file exists*/
/*access checks whether the calling process can access the file pathname 
(first input)*/
/*execve executes the program being reffered to by the first input*/

int	find_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int		i;
	char	*thecmd;

	i = 0;
	cmd->str = resplit_str(cmd->str);
	if (!access(cmd->str[0], F_OK))
		execve(cmd->str[0], cmd->str, tools->envp);
	while (tools->paths[i])
	{
		thecmd = ft_strjoin(tools->paths[i], cmd->str[0]);
		if (!access(thecmd, F_OK))
			execve(thecmd, cmd->str, tools->envp);
		free(thecmd);
		i++;
	}
	return (cmd_not_found(cmd->str[0]));
}

void	handle_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->redirections)
		if (check_redirections(cmd))
			exit(1);
	if (cmd->builtin != NULL)
	{
		exit_code = cmd->builtin(tools, cmd);
		exit(exit_code);
	}
	else if (cmd->str[0][0] != '\0')
		exit_code = find_cmd(cmd, tools);
	exit(exit_code);
}

/*dup2(int oldfd, int newfd) allocates a new file descriptor that 
refers to the same open file description as the the descriptor oldfd
 - using the file descriptor number defined in newfd - newfd is changed
to it refers to the same open file description as oldfd*/

void	dup_cmd(t_simple_cmds *cmd, t_tools *tools, int end[2], int fd_in)
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		ft_error(4, tools);
	close(end[0]);
	if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
		ft_error(4, tools);
	close(end[1]);
	if (cmd->prev)
		close(fd_in);
	handle_cmd(cmd, tools);
}

void	single_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int	pid;
	int	status;

	tools->simple_cmds = call_expander(tools, tools->simple_cmds);
	if (cmd->builtin == mini_cd || cmd->builtin == mini_exit
		|| cmd->builtin == mini_export || cmd->builtin == mini_unset)
	{
		g_global.error_num = cmd->builtin(tools, cmd);
		return ;
	}
	send_heredoc(tools, cmd);
	pid = fork();
	if (pid < 0)
		ft_error(5, tools);
	if (pid == 0)
		handle_cmd(cmd, tools);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
}
