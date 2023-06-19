/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:29:44 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/19 13:52:28 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec_cmd	*create_exec_cmd(void)
{
	t_exec_cmd	*cmd;

	cmd = ft_calloc(sizeof(t_exec_cmd), 1);
	if (!cmd)
		return (NULL);
	cmd->type = EXEC;
	return (cmd);
}

t_pipe_cmd	*create_pipe_cmd(t_cmd *left, t_cmd *right)
{
	t_pipe_cmd	*cmd;

	cmd = ft_calloc(sizeof(t_pipe_cmd), 1);
	if (!cmd)
		return (NULL);
	cmd->type = PIPE;
	cmd->left = left;
	cmd->right = right;
	return (cmd);
}

t_redir_cmd	*create_redir_cmd(t_cmd *sub_cmd, char *file, char *efile, int mode, int fd)
{
	t_redir_cmd	*cmd;

	cmd = ft_calloc(sizeof(t_redir_cmd), 1);
	if (!cmd)
		return (NULL);
	cmd->type = REDIR;
	cmd->cmd = sub_cmd;
	cmd->file = file;
	cmd->efile = efile;
	cmd->mode = mode;
	cmd->fd = fd;
	return (cmd);
}
