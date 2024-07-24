/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:45:57 by raphox            #+#    #+#             */
/*   Updated: 2024/07/24 19:02:09 by rafaria          ###   ########.fr       */
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
	// printf("\n Le chemin : %s \n ------", envp[i]);
	paths = ft_split(envp[i] + 5, ':');
	printf("\n Le chemin  valide: %s \n ------", paths[0]);
	printf("\n Le chemin  valide: %s \n ------", paths[1]);
	printf("\n Le chemin  valide: %s \n ------", paths[2]);
	printf("\n Le chemin  valide: %s \n ------", paths[3]);
	printf("\n Le chemin  valide: %s \n ------", paths[4]);
	printf("\n Le chemin  valide: %s \n ------", paths[5]);
	printf("\n Le chemin  valide: %s \n ------", paths[6]);
	printf("\n Le chemin  valide: %s \n ------", paths[7]);
	
	i = 0;
	while(paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		printf("\n Le dernier chemin valide: %s \n ------", path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}	
	return (NULL);
}



int execute(char *string, char **envp)
{
	char *path;
	char **cmd;
	cmd = ft_split(string, ' ');
	printf("La commande : %s \n ------", cmd[0]);

	path = find_path(cmd[0], envp);
	printf("\n\n\n\n Resultat :");
	execve(path, cmd, envp);
	return (0);
	
}

int	main(int a,char **av, char **envp)
{
	// int p_fd[2];
	// pid_t pid;
	// pid = fork();
	// dup2();
	a = 4;
	execute(av[1], envp);
	return (0);
	
}