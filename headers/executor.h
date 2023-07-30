/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:50:06 by eclark            #+#    #+#             */
/*   Updated: 2023/07/30 17:54:32 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "lexer.h"
# include "utils.h"

/*executor utils*/
char			**resplit_str(char **double_arr);
char			*join_split_str(char **split_str, char *new_str);

/*check_redirections*/
int				handle_outfile(t_lexer *redirection);
int				handle_infile(char *file);
int				check_append_outfile(t_lexer *redirections);
int				check_redirections(t_simple_cmds *cmd);

/*executor*/
int				excecutor(t_tools *tools);
int				check_fd_heredoc(t_tools *tools, int end[2], 
					t_simple_cmds *cmd);
int				ft_fork(t_tools *tools, int end[2], int fd_in, 
					t_simple_cmds *cmd);
int				pipe_wait(int *pid, int amt);
t_simple_cmds	*expander_call(t_tools *tools, t_simple_cmds *cmd);

/*handle_cmds*/
void			single_cmd(t_simple_cmds *cmd, t_tools *tools);
void			dup_cmd(t_simple_cmds *cmd, t_tools *tools, int end[2], 
					int fd_in);
void			handle_cmd(t_simple_cmds *cmd, t_tools *tools);
int				find_cmd(t_simple_cmds *cmd, t_tools *tools);

/*heredoc*/
int				create_heredoc(t_lexer *heredoc, bool quotes, t_tools *tools,
					char *file_name);
int				ft_heredoc(t_tools *tools, t_lexer *heredoc, char *file_name);
char			*generate_heredoc_filename(void);
int				send_heredoc(t_tools *tools, t_simple_cmds *cmd);

typedef struct s_tools
{
	char					*args;
	char					**paths;
	char					**envp;
	struct s_simple_cmds	*simple_cmds;
	t_lexer					*lexer_list;
	char					*pwd;
	char					*old_pwd;
	int						pipes;
	int						*pid;
	bool					heredoc;
	bool					reset;
}	t_tools;

typedef struct s_simple_cmds
{
	char					**str;
	int						(*builtin)(t_tools *, struct s_simple_cmds *);
	int						num_redirections;
	char					*hd_file_name;
	t_lexer					*redirections;
	struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
}	t_simple_cmds;

#endif