/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:45:57 by raphox            #+#    #+#             */
/*   Updated: 2024/07/29 17:41:38 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find_path(char *cmd, char **envp)
{
	int i;
	char *path;
	char *part_path;
	char **paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');	
	i = 0;
	while(paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = 0;
	while(paths[i])
		free(paths[i]);
	free(paths);
	return (NULL);
}

void	error()
{
	exit(EXIT_FAILURE);
}


int execute(char *string, char **envp)
{
	char *path;
	char **cmd;
	cmd = ft_split(string, ' ');
	path = find_path(cmd[0], envp);
	printf("\n\n\n\n Resultat :");
	execve(path, cmd, envp);
	return (0);
	
}


void first_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	//toute sortie envoyée vers la sortie standard sera désormais redirigée 
	// vers le pipe, et non plus affichée sur l'écran.
	dup2(filein, STDIN_FILENO); 
	// L entree se fait a partir du fichier
	close(fd[0]);
	execute(argv[2], envp);
}
void	second_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int ac, char **av,  char **envp)
{
	int fd[2];
	pid_t pid1;
	
	if (ac == 5)
	{
		if(pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)	
			first_process(av, envp, fd);
		waitpid(pid1, NULL, 0);
		second_process(av, envp, fd);
	}
	else
		write(1," Bad arguments, do better\n", 27);
	return (0);
	
}