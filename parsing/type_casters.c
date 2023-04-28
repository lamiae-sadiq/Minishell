/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_casters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:05:50 by aanouari          #+#    #+#             */
/*   Updated: 2023/04/27 17:10:17 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	d_quote_cast(char *stack)
{
	if (stack[0] == SINGLE_QUOTE
		&& stack[ft_strlen(stack) - 1] == SINGLE_QUOTE)
		return (BETWIXT_SQ);
	else if (stack[0] == DOUBLE_QUOTE
		&& stack[ft_strlen(stack) - 1] == DOUBLE_QUOTE)
		return (BETWIXT_DQ);
	else
		return (DEFAULTED);
}

int	set_type(int status, char *shaft)
{
	if (status == BETWIXT_DQ || status == BETWIXT_SQ)
		return (LITERAL);
	else if (shaft[0] == 62 || shaft[0] == 60 || shaft[0] == 124)
		return(OPERATOR);
	else
		return (KEYWORD);
}
