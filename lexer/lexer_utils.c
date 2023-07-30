/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:23:38 by eclark            #+#    #+#             */
/*   Updated: 2023/07/30 17:24:37 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ignore_space(char *str, int args)
{
	int	i;

	i = 0;
	while (str[args + i] == " " || (str[args + i] > 8 && str[args + i] < 14))
	{
		i++;
	}
	return (i);
}

int	quotes_process(int i, char *str, char del)
{
	int	j;

	j = 0;
	if (str[i + j] == del)
	{
		j++;
		while (str[i + j] != del && str[i + j])
			j++;
		j++;
	}
	return (j);
}

int	add_node(char *str, t_tokens token, t_lexer **list)
{
	t_lexer	*node;

	node = ft_lexernew(str, token);
	if (!node)
		return (0);
	ft_lexeradd_back(list, node);
	return (1);
}
