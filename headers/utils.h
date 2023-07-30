/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:57:05 by eclark            #+#    #+#             */
/*   Updated: 2023/07/30 17:58:35 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "lexer.h"
# include "minishell.h"

typedef struct s_utils
{
	char	*args;
	t_lexer	*list;
}	t_utils;

/*parser_envp*/
int				find_pwd(t_tools *tools);
char			*find_path(char **envp);
int				parse_envp(t_tools *tools);

/*t_lexer utils*/
void			ft_lexeradd_back(t_lexer **lst, t_lexer *new);
t_lexer			*ft_lexernew(char *str, int token);

/*t_simple_cmds_utils*/
t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *map);
void			ft_simple_cmdsclear(t_simple_cmds **lst);
void			ft_simple_cmds_rm_first(t_simple_cmds **lst);
void			ft_simple_cmdsadd_back(t_simple_cmds **lst, t_simple_cmds *new);
t_simple_cmds	*ft_simple_cmdsnew(char **str,
					int num_redirections, t_lexer *redirections);

/*t_lexer_clear_utils*/
void			ft_lexerclear(t_lexer **lst);
t_lexer			*ft_lexerclear_one(t_lexer **lst);
void			ft_lexerdel_first(t_lexer **lst);
void			ft_lexerdelone(t_lexer **lst, int key);

/*utils*/
char			**ft_arrdup(char **arr);
int				find_matching_quote(char *line, int i, int *num_del, int del);
int				count_quotes(char *line);

/*minishell loop*/
int				minishell_loop(t_tools *tools);

#endif