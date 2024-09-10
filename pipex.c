/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:45:57 by raphox            #+#    #+#             */
/*   Updated: 2024/09/10 15:26:04 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
	{
		error(3, argv[1]);
		exit(EXIT_FAILURE);
	}
	dup2(filein, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(filein);
	close(fd[0]);
	close(fd[1]);
	execute(argv[2], envp);
}

void	second_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
	{
		error(0, NULL);
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	close(fd[1]);
	close(fd[0]);
	execute(argv[3], envp);
}

void	ft_close(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error(0, NULL);
		pid1 = fork();
		if (pid1 == -1)
			error(0, NULL);
		if (pid1 == 0)
			first_process(av, envp, fd);
		pid2 = fork();
		if (pid2 == -1)
			error(0, NULL);
		if (pid2 == 0)
			second_process(av, envp, fd);
		ft_close(fd);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		write(2, "Bad arguments, do better !\n", 28);
	return (0);
}
