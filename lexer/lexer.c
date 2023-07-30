/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:24:44 by eclark            #+#    #+#             */
/*   Updated: 2023/07/30 17:26:00 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/* create lexer that breaks down command given in the input to
 seperate tokens for the parser to interpret.

 Seperates words from options eg.

 ls -l 

 ls will be turned into a token word
 -l will read the - and l seperately and will become an option token. */

/*checking if the argument inputted includes one of the three tokens
 the pipe |, >  or <. returns the enum identifier for each eg PIPE
  for |.*/
t_tokens	token_check(int c)
{
	int			i;
	static int	tokens[3][2] = 
	{{'|', PIPE}, {'>', GREAT}, {'<', LESS},};

	i = 0;
	while (i < 3)
	{
		if (tokens[i][0] == c)
			return (tokens[i][1]);
		i++;
	}
	return (0);
}

/* this processes each individual token identified - and checks
 for possible double tokens eg || or >> and adds an additional node to the 
 lexer list.*/
int	token_process(char *str, int i, t_lexer **list)
{
	t_tokens	token;

	token = token_check(str[i]);
	if (token == GREAT && check_token(str[i + 1]) == GREAT)
	{
		if (!add_node(NULL, GREAT_GREAT, list))
			return (-1);
		return (2);
	}
	else if (token == LESS && token_check(str[i + 1]) == LESS)
	{
		if (!add_node(NULL, LESS_LESS, list))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!add_node(NULL, token, list))
			return (-1);
		return (1);
	}
	return (0);
}

/* if no token is identified it will process the words in the argument
given - includes handling single and double quotes will continue until whitespace
or token is identified*/
int	word_process(char *str, int i, t_lexer **list)
{
	int	j;

	j = 0;
	while (str[i + j] && !(token_check(str[i + j])))
	{
		j = j + quotes_process(i + j, str, 34);
		j = j + quotes_process(i + j, str, 39);
		if ((str[i + j] == " " || (str[i + j] > 8 && str[i + j] < 14)))
			break ;
		else
			j++;
	}
	if (!add_node(ft_substr(str, i, j), 0, list))
		return (-1);
	return (j);
}

int	lexer(t_utils *utils)
{
	int	i;
	int	j;

	i = 0;
	while (utils->args[i])
	{
		j = 0;
		while (utils->args[i])
		{
			j = 0;
			ignore_space(utils->args, i);
			if (token_check(utils->args[i]))
				j = token_process(utils->args, i, &utils->list);
			else
				j = word_process(utils->args, i, &utils->list);
			if (j < 0)
				return (0);
			i = i + j;
		}
		return (1);
	}
}
