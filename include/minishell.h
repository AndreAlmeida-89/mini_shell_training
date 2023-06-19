/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:21:32 by pvieira-          #+#    #+#             */
/*   Updated: 2023/06/19 11:21:57 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/ft_printf/include/ft_printf.h"
# include <fcntl.h>
# include <sys/wait.h>

# define MAX_ARGS 10

typedef enum e_type
{
	EXEC = 1,
	PIPE,
	REDIR,
}	t_type;

typedef struct s_cmd
{
	t_type	type;
}	t_cmd;

typedef struct s_exec_cmd
{
	t_type	type;
	char	*argv[MAX_ARGS];
	char	*eargv[MAX_ARGS];
}	t_exec_cmd;

typedef struct s_pipe_cmd
{
	t_type	type;
	t_cmd	*right;
	t_cmd	*left;
}	t_pipe_cmd;

typedef struct s_redir_cmd
{
	t_type	type;
	t_cmd	*cmd;
	char	*file;
	char	*efile;
	int		mode;
	int		fd;
}	t_redir_cmd;


t_cmd		*parse_cmd(char *buffer);
void		runcmd(t_cmd *cmd);
t_exec_cmd	*create_exec_cmd(void);
t_pipe_cmd	*create_pipe_cmd(t_cmd *left, t_cmd *right);
t_redir_cmd	*create_redir_cmd(t_cmd *sub_cmd, char *file, char *efile, int mode, int fd);


//Utils
void		ft_panic(char *str);
pid_t		ft_fork(void);
void		ft_put_error(char *str);

#endif
