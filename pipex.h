/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:10:50 by raphox            #+#    #+#             */
/*   Updated: 2024/09/10 14:39:59 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	error(int i, char *str);
int		main(int ac, char **av, char **envp);
void	ft_close(int *fd);

void	first_process(char **argv, char **envp, int *fd);
void	second_process(char **argv, char **envp, int *fd);

void	execute(char *string, char **envp);
char	*find_path(char *cmd, char **envp);
char	**ft_split(char *s, char c);
void	final_execute(char *path, char **cmd, char **envp);

#endif