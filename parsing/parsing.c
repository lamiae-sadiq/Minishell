/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:38:12 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/28 14:53:51 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_tree(char **stack, t_token **shaft)
{
	int		i;
	t_token	*cast;

	i = -1;
	cast = (*shaft);
	if (!stack)
		return ;
	while (stack[++i])
		token_addback(shaft, token_new(ft_strdup(stack[i])));
}

void	casting(t_token **shaft)
{
	t_token	*cast;

	cast = *shaft;
	while (cast)
	{
		cast->status = d_quote_cast(cast->content);
		cast->type = set_type(cast->status, cast->content);
		cast = cast->next;
	}
}