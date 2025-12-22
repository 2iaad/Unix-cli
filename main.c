/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD:tools/tool_1.c
/*   tool_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:14:32 by zderfouf          #+#    #+#             */
/*   Updated: 2024/05/04 10:22:39 by zderfouf         ###   ########.fr       */
=======
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:07:28 by ibouram           #+#    #+#             */
/*   Updated: 2024/08/04 18:42:09 by zderfouf         ###   ########.fr       */
>>>>>>> origin/ziad:main.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD:tools/tool_1.c
void    ft_free(char **str)
{
    int i;

    i = -1;
    while (str[++i])
        free(str[i]);
    free(str);
}

int ft_strlen(char *str)
=======
int	main(int ac, char **av, char **envp)
>>>>>>> origin/ziad:main.c
{
	t_final	final_cmd;
	t_env	*env_list;

<<<<<<< HEAD:tools/tool_1.c
    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_putstr(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        write(1, &str[i], 1);
}

int ft_strcmp(char *s1, char *s2, int len)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i] && i < len)
        i++;
    return(s1[i] - s2[i]);
=======
	rl_catch_signals = 0;
	(void)av;
	g_signal = 0;
	if (ac > 1)
	{
		write(2, "Error: too many arguments\n", 26);
		return (1);
	}
	init_env(&env_list, envp);
	read_from_input(&final_cmd, &env_list, envp);
>>>>>>> origin/ziad:main.c
}

int flag_check(char *s1) // check if s1 == "-n" or -nnnnnnn
{
    int i;

	if (ft_strcmp(s1, "-n", 1)) // if not real flag "-n"
		return (1);
    i = 2;
	while (s1[i]) // if not real flag "-nnnnx"
	{
		if (s1[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}
