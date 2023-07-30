/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:49:47 by eclark            #+#    #+#             */
/*   Updated: 2023/07/30 17:49:51 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "minishell.h"

void	parser_error(int error, t_tools *tools, t_lexer *lexer_list);
int		parser_double_token_error(t_tools *tools, t_lexer *lexer_list,
			t_tokens token);
void	lexer_error(int error, t_tools *tools);
int		cmd_not_found(char *str);
int		export_error(char *c);

int		ft_error(int error, t_tools *tools);

#endif