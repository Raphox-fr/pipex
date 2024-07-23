/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:39:35 by raphox            #+#    #+#             */
/*   Updated: 2023/11/16 14:56:28 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}

int	ft_checkset(char const *set, char const to_find)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		min;
	int		max;
	int		fine;
	char	*main_str;

	min = 0;
	max = 0;
	fine = ft_strlen(s1);
	while (ft_checkset(set, s1[min]) == 1)
		min++;
	while (ft_checkset(set, s1[fine - 1]) == 1)
	{
		fine--;
		max++;
	}
	main_str = malloc(sizeof(char) * (((ft_strlen(s1) - min) - max)));
	fine = 0;
	while (min < (ft_strlen(s1) - max))
	{
		main_str[fine] = s1[min];
		fine++;
		min++;
	}
	main_str[fine] = '\0';
	return (main_str);
}

int	main(void)
{
	char const	set[] = " b   ";
	char const	s1[] = "     b bonjour   ";

	printf("%s", ft_strtrim(s1, set));
}