/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:35:16 by lsadiq            #+#    #+#             */
/*   Updated: 2023/06/26 14:24:36 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_invalid_exit(char *str)
{
	int				i;
	unsigned long	num;
	int				sign;

	i = -1;
	num = 0;
	sign = 1;
	while ((str[++i] >= 9 && str[i] <= 13) || str[i] == 32)
		;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - 48;
		if (num > 9223372036854775807 && sign == 1)
			return (1);
		else if (num > 9223372036854775807 && sign == -1)
			return (1);
	}
	return (0);
}

int	ft_exit(void)
{
	t_vdata	*tmp;
	int		i;
	char	c;

	i = 1;
	tmp = g_data.ms;
	c = 0;
	printf("exit\n");
	if (tmp->stack[1] == NULL)
		exit(127);
	c = ft_atoi(tmp->stack[i]);
	if (ft_invalid_exit(tmp->stack[i]))
	{
		ft_dprintf(2, "minishell : exit %s : numeric argument required\n",
			tmp->stack[i]);
		exit(255);
	}
	if (tmp->stack[1] && tmp->stack[2])
	{
		ft_putstrr_fd("minishell : exit : too many arguments\n", 2);
		g_data.exit_s = 1;
		return (0);
	}
	exit(c);
}
