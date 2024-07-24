/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:45:57 by raphox            #+#    #+#             */
/*   Updated: 2024/07/24 14:31:34 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int find_path(char **envp)
{
	int i;
	char *path;

	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path = ft_split(envp[i][5], ':');
	execve()
	
}



int execute(int ac, char **av)
{
	char **cmd;
	cmd = ft_split(av, ' ');

	find_path()
	
	
	
}

int	main(int ac, char **av, char **envp)
{
	int p_fd[2];
	pid_t pid;
	pid = fork();
	
	
	

	dup2();
	
}