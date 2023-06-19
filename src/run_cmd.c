/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:35:03 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/19 14:53:20 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	runcmd(t_cmd *cmd)
{
	int			p[2];
	t_exec_cmd	*ecmd;
	t_pipe_cmd	*pcmd;
	t_redir_cmd	*rcmd;

	if (cmd == NULL)
		exit(1);
	if (cmd->type == EXEC)
	{
		ecmd = (t_exec_cmd *)cmd;
		if (ecmd->argv[0] == NULL)
			exit(1);
		execv(ecmd->argv[0], ecmd->argv);
		ft_put_error(ecmd->argv[0]);
	}
	else if (cmd->type == REDIR)
	{
		rcmd = (t_redir_cmd *)cmd;
		close(rcmd->fd);
		if (open(rcmd->file, rcmd->mode) < 0)
		{
			ft_put_error(rcmd->file);
			exit(1);
		}
		runcmd(rcmd->cmd);
	}
	else if (cmd->type == PIPE)
	{
		pcmd = (t_pipe_cmd *)cmd;
		if (pipe(p) < 0)
			ft_panic("PIPE");
		if (ft_fork() == 0)
		{
			close(1);
			dup(p[1]);
			close(p[0]);
			close(p[1]);
			runcmd(pcmd->left);
		}
		if (ft_fork() == 0)
		{
			close(0);
			dup(p[0]);
			close(p[0]);
			close(p[1]);
			runcmd(pcmd->right);
		}
		close(p[0]);
		close(p[1]);
		wait(0);
		wait(0);
	}
	else
		ft_panic("RUN COMMAND");
	exit(EXIT_SUCCESS);
}
