/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:12:06 by andde-so          #+#    #+#             */
/*   Updated: 2023/06/19 14:54:43 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*buffer;
	int		fd;

	// Garante que 3 fds são abertos
	while ((fd = open("console", O_RDWR)) >= 0)
	{
		if (fd >= 3)
		{
			close(fd);
			break ;
		}
	}
	if (argc != 1 || argv[1] || !env)
		return (1);
	while (42)
	{
		buffer = readline("Mini>");
		if (ft_strncmp("exit", buffer, 5) == 0)
			break ;
		if (ft_fork() == 0)
			runcmd(parse_cmd(buffer));
		wait(0);
	}
	return (EXIT_SUCCESS);
}