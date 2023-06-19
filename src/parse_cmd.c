/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:55:28 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/19 16:24:52 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

t_cmd	*parse_cmd(char *buffer)
{

	(void)buffer; //considerando o buffer: ls -al | grep main.c
	t_exec_cmd	*cmd1;
	t_exec_cmd	*cmd2;
	t_pipe_cmd	*pcdm;


	cmd1 = create_exec_cmd();
	cmd1->argv[0] = "/bin/ls";
	cmd1->argv[1] = "-al";
	cmd1->argv[3] = NULL;

	cmd2 = create_exec_cmd();
	cmd2->argv[0] = "/usr/bin/grep";
	cmd2->argv[1] = "Makefile";
	cmd2->argv[3] = NULL;

	pcdm = create_pipe_cmd((t_cmd *)cmd1, (t_cmd *)cmd2);

	return ((t_cmd *)pcdm);
	/*
	(void)buffer; //considerando o buffer: ls -al > result.txt
	t_exec_cmd	*cmd1;
	t_redir_cmd	*rcmd;

	cmd1 = create_exec_cmd();
	cmd1->argv[0] = "/bin/ls";
	cmd1->argv[1] = "-al";
	cmd1->argv[3] = NULL;

	rcmd = create_redir_cmd((t_cmd *)cmd1, "result.txt", NULL, O_RDWR | O_CREAT, 1);

	return ((t_cmd *)rcmd);
	*/
}