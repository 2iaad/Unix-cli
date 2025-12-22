/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:includes/tools.h
/*   Created: 2024/05/03 10:13:21 by zderfouf          #+#    #+#             */
/*   Updated: 2024/05/04 10:09:09 by zderfouf         ###   ########.fr       */
=======
/*   Created: 2024/05/03 10:17:21 by zderfouf          #+#    #+#             */
/*   Updated: 2024/07/29 09:16:47 by zderfouf         ###   ########.fr       */
>>>>>>> origin/ziad:execution/builtins/echo.c
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

<<<<<<< HEAD:includes/tools.h
#include "minishell.h"

int     ft_strlen(char *str);
void    ft_free(char **str);
int     ft_strcmp(char *s1, char *s2, int len);
int     flag_check(char *s1);
char	**ft_split(const char *s, char c);
void    ft_putstr(char *str);
=======
void	echo(t_final	*lst)
{
	int	i;
	int	flag;
>>>>>>> origin/ziad:execution/builtins/echo.c

	i = 1;
	if (!lst->final_cmd[1])
		return ((void) write(1, "\n", 1));
	flag = flag_check(lst->final_cmd[1]);
	while (lst->final_cmd[i])
	{
		if (flag_check(lst->final_cmd[i]))
			break ;
		i++;
	}
	while (lst->final_cmd[i])
	{
		ft_putstr_fd(lst->final_cmd[i], 1);
		if (lst->final_cmd[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (flag)
		write(1, "\n", 1);
	exit_status(0, 1);
}
