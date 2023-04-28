/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:24:03 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/27 17:24:45 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_new(char *content)
{
	t_token	*tab;

	tab = (t_token *) ft_calloc(1, sizeof(t_token));
	tab->content = content;
	tab->type = 0;
	tab->status = 0;
	tab->next = NULL;
	return (tab);
}

int	clear_tokens(t_token **token)
{
	t_token	*current;
	t_token	*next;

	if (!token)
		return (1);
	current = (*token);
	next = (*token);
	while (current)
	{
		next = next->next;
		free(current);
		current = next;
	}
	*token = NULL;
	return (1);
}

void	token_addback(t_token **token, t_token *_new)
{
	t_token	*current;

	if (!token || !_new)
		return ;
	current = (*token);
	if (!current)
	{
		*token = _new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = _new;
}

void	token_addfront(t_token **token, t_token *_new)
{
	if (!_new)
		return ;
	if (!token)
	{
		*token = _new;
		return ;
	}
	_new->next = (*token);
	(*token) = _new;
}