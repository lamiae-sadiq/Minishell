/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:30:11 by lsadiq            #+#    #+#             */
/*   Updated: 2023/06/26 14:42:18 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_remove(char **env, int k)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	j = 0;
	tmp = malloc(sizeof(char *) * ft_arrsize(env));
	if (!tmp)
		return (NULL);
	while (env[++i])
		if (i != k)
			tmp[j++] = ft_strdup(env[i]);
	tmp[j] = NULL;
	ft_free2d(env);
	return (tmp);
}

int	ft_unset(int i, int k, t_shell *tmp)
{
	tmp = &g_data;
	if (tmp->ms->stack[1] == NULL)
		return (0);
	while (tmp->ms->stack[++i])
	{
		if (ft_alpha(tmp->ms->stack[i][0]))
		{
			while (tmp->env[++k])
			{
				if (!ft_strncmp(tmp->ms->stack[i], tmp->env[k],
						ft_strlen(tmp->ms->stack[i])))
				{
					tmp->env = ft_remove(tmp->env, k);
					break ;
				}
			}
		}
		else
		{
			ft_dprintf(2, UNSET_UNVALID, tmp->ms->stack[i]);
			return (g_data.exit_s = 1);
		}
	}
	return (g_data.exit_s = 0);
}