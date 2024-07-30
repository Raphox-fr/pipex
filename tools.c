/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:38:34 by rafaria           #+#    #+#             */
/*   Updated: 2024/07/30 15:03:04 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	exit(EXIT_FAILURE);
}

void	execute(char *string, char **envp)
{
	int		i;
	char	*path;
	char	**cmd;

	i = 0;
	cmd = ft_split(string, ' ');
	if (cmd == NULL)
		error();
	path = find_path(cmd[0], envp);
	if (path == NULL)
	{
		while (cmd[i])
			free(cmd[i]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	*part_path;
	char	**paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
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
	while (paths[i])
		free(paths[i]);
	free(paths);
	return (NULL);
}
