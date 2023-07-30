/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:43:14 by eclark            #+#    #+#             */
/*   Updated: 2023/07/30 17:44:42 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*open(const char *pathname, int flags, mode_t mode)
O_CREAT : if pathname does not exist, create as a regular file
O_RDWR : access to read and write file
O_TRUNC : if the file already exists and is a regular file and
is able to be written it will trunicate to length 0, deleting
previous information in the file*/

int	create_heredoc(t_lexer *heredoc, bool quotes, t_tools *tools,
	char *file_name)
{
	char	*line;
	int		fd;

	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	line = readline(HEREDOC_MSG);
	while (line && ft_strncmp(heredoc->str, line, ft_strlen(heredoc->str))
		&& !g_global.stop_heredoc)
	{
		if (quotes == false)
			line = expander_str(tools, line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline(HEREDOC_MSG);
	}
	free(line);
	if (g_global.stop_heredoc || !line)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_heredoc(t_tools *tools, t_lexer *heredoc, char *file_name)
{
	bool	quotes;
	int		sl;

	sl = EXIT_SUCCESS;
	if ((heredoc->str[0] == '\"'
			&& heredoc->str[ft_strlen(heredoc->str) - 1] == '\"')
		|| (heredoc->str[0] == '\''
			&& heredoc->str[ft_strlen(heredoc->str) - 1] == '\''))
		quotes = true;
	else
		quotes = false;
	delete_quotes(heredoc->str, '\"');
	delete_quotes(heredoc->str, '\'');
	g_global.stop_heredoc = 0;
	g_global.in_heredoc = 1;
	sl = create_heredoc(heredoc, quotes, tools, file_name);
	g_global.in_heredoc = 0;
	tools->heredoc = true;
	return (sl);
}

char	*generate_heredoc_filename(void)
{
	static int	i;
	char		*num;
	char		*file_name;

	num = ft_itoa(i++);
	file_name = ft_strjoin("build/.tmp_heredoc_file_", num);
	free(num);
	return (file_name);
}

int	send_heredoc(t_tools *tools, t_simple_cmds *cmd)
{
	t_lexer	*start;
	int		sl;

	start = cmd->redirections;
	sl = EXIT_SUCCESS;
	while (cmd->redirections)
	{
		if (cmd->redirections->token == LESS_LESS)
		{
			if (cmd->hd_file_name)
				free(cmd->hd_file_name);
			cmd->hd_file_name = generate_heredoc_filename();
			sl = ft_heredoc(tools, cmd->redirections, cmd->hd_file_name);
			if (sl)
			{
				g_global.error_num = 1;
				return (reset_tools(tools));
			}
		}
		cmd->redirections = cmd->redirections->next;
	}
	cmd->redirections = start;
	return (EXIT_SUCCESS);
}
