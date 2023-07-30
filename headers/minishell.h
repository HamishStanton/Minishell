/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:55:35 by eclark            #+#    #+#             */
/*   Updated: 2023/07/30 17:56:01 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "executor.h"
# include "lexer.h"
# include "parser.h"
# include "utils.h"
# include "colour.h"
# include "error.h"
# include "builtins.h"

# include <stdio.h>
# include <signal.h>
# include <unistd.h>

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

typedef struct s_global
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;

t_global	g_global;

int			event(void);
void		sigint_handler(int sig);
void		sigquit_handler(int sig);
void		init_signals(void);

#endif