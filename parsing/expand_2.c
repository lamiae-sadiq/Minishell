/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 05:09:00 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/23 14:24:23 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*cancel_quotes(char	*file, bool free_file)
{
	char	*buffer;
	char	quote;
	int		i;

	i = 0;
	buffer = NULL;
	while (file[i])
	{
		if (file[i] == DOUBLE_QUOTE || file[i] == SINGLE_QUOTE)
		{
			quote = file[i++];
			while (file[i] != quote && file[i])
				buffer = s_concatinate(buffer, file[i++]);
			i++;
		}
		if (file[i] && file[i] != DOUBLE_QUOTE && file[i] != SINGLE_QUOTE)
			buffer = s_concatinate(buffer, file[i++]);
	}
	if (!buffer)
		buffer = ft_strdup("");
	if (free_file)
		free(file);
	return (buffer);
}

void	quote_expansion(t_vdata *ms)
{
	int		i;

	i = -1;
	while (ms->stack && ms->stack[++i])
	{
		ms->stack[i] = expand(ms->stack[i], 1);
		if (ft_strchr(ms->stack[i], '\'') || ft_strchr(ms->stack[i], '"'))
			ms->stack[i] = cancel_quotes(ms->stack[i], 1);
	}
}
