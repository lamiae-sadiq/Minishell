/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:47:54 by lsadiq            #+#    #+#             */
/*   Updated: 2023/06/26 15:09:41 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	heredoc_sig(int signal)
{
	if (signal == SIGINT)
	{
		g_data.exit_s = 1;
		exit(EXIT_FAILURE);
	}
}

int	ft_parent(int *status)
{
	waitpid(-1, status, 0);
	if (WIFSIGNALED(*status))
	{
		g_data.exit_s = 128 + WTERMSIG(*status);
		return (1);
	}
	return (0);
}

int	ft_checkone(char *line, char *q_file)
{
	if (!line || ft_strcmp(q_file, line) == 0)
	{
		if (line)
			free(line);
		return (1);
	}
	return (0);
}

void	ft_handle_line(char *line, char *file, int fd)
{
	if (ft_strlen(line) > 0 && (!ft_strchr(file, '\"')
			&& !ft_strchr(file, '\'')))
		line = expand(line, 0);
	ft_dprintf(fd, "%s\n", line);
	free(line);
}

int	open_here_doc(char *file, int fd, int status, char *line)
{
	char	*q_file;
	int		end[2];
	pid_t	id;

	pipe(end);
	id = fork();
	if (file && !id)
	{
		ft_here_sig();
		q_file = cancel_quotes(file, 0);
		fd = ft_reverse_fd(end, 0);
		while (1)
		{
			line = readline(YELLOW ">" RESET);
			if (ft_checkone(line, q_file))
				break ;
			ft_handle_line(line, file, fd);
		}
		free(q_file);
		close(fd);
		exit(0);
	}
	else if (ft_parent(&status))
		return (-1);
	return (ft_reverse_fd(end, 1));
}