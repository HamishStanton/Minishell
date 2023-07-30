/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:53:34 by hstanton          #+#    #+#             */
/*   Updated: 2023/07/30 17:20:05 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser_tools	init_parser_tools(t_lexer *lexer_list, t_tools *tools)
{
	t_parser_tools	parser_tools;

	parser_tools.lexer_list = lexer_list;
	parser_tools.redirections = NULL;
	parser_tools.num_redirections = 0;
	parser_tools.tools = tools;
	return (parser_tools);
}

void	count_pipes(t_lexer *lexer_list, t_tools *tools)
{
	t_lexer	*tmp;

	tmp = lexer_list;
	tools->pipes = 0;
	while (tmp)
	{
		if (tmp->token == PIPE)
			tools->pipes++;
		tmp = tmp->next;
	}
}

int	count_args(t_lexer *lexer_list)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = lexer_list;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->i >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_lexer	*find_next_cmd(t_lexer *lexer_list)
{
	while (lexer_list && lexer_list->token != PIPE)
		lexer_list = lexer_list->next;
	return (lexer_list);
}
