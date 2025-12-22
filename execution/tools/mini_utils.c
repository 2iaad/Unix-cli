/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:includes/minishell.h
/*   Created: 2024/05/03 10:12:29 by zderfouf          #+#    #+#             */
/*   Updated: 2024/05/04 15:47:04 by zderfouf         ###   ########.fr       */
=======
/*   Created: 2024/05/03 10:14:32 by zderfouf          #+#    #+#             */
/*   Updated: 2024/07/30 19:14:24 by zderfouf         ###   ########.fr       */
>>>>>>> origin/ziad:execution/tools/mini_utils.c
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

<<<<<<< HEAD:includes/minishell.h
#include "tools.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_cmd
{
    char **str;
}   t_cmd;

/*          BUILTINS        */

void    echo(char   **cmd);
void    cd(char **cmd);
void    pwd(char **str);
=======
void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		free(str[i]);
	free(str);
}
>>>>>>> origin/ziad:execution/tools/mini_utils.c

int	ft_strncmp(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < len)
		i++;
	return (s1[i] - s2[i]);
}

int	flag_check(char *s1)
{
	int	i;

	if (ft_strncmp(s1, "-n", 1))
		return (1);
	i = 2;
	while (s1[i])
	{
		if (s1[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}
