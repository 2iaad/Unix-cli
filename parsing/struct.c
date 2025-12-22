/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:30:14 by ibouram           #+#    #+#             */
/*   Updated: 2024/08/04 18:31:25 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	process_file_type(t_token **node, t_final **tmp, int *files_index)
{
	(*tmp)->files[*files_index].file = ft_strdup((*node)->token);
	if ((*node)->type == DELIMITER)
	{
		if ((*node)->flg == 1)
			(*tmp)->files[*files_index].flg = 1;
		else
			(*tmp)->files[*files_index].flg = 0;
	}
	(*tmp)->files[(*files_index)++].type = (*node)->type;
}

void	token_type(t_token **node, t_final **tmp, int *opt_index, int *fl_index)
{
	if (!node || !(*node) || !tmp || !(*tmp))
		return ;
	if ((*node)->type == CMD)
	{
		(*tmp)->cmd = ft_strdup((*node)->token);
		(*tmp)->var_flg = 0;
		if ((*node)->var_flg == 1)
			(*tmp)->var_flg = 1;
	}
	else if ((*node)->type == OPTION)
		(*tmp)->args[(*opt_index)++] = ft_strdup((*node)->token);
	else if ((*node)->type == IN_FILE || (*node)->type == OUT_FILE
		|| (*node)->type == AOUT_FILE || (*node)->type == DELIMITER)
		process_file_type(node, tmp, fl_index);
}

void	node_process(t_token **node, t_final **tmp, int *opt_indx, int *fl_indx)
{
	while (*node && (*node)->type != PIPE)
	{
		token_type(node, tmp, opt_indx, fl_indx);
		*node = (*node)->next;
	}
}

void	move_next_node(t_token **node)
{
	if ((*node)->type == PIPE)
		*node = (*node)->next;
}

t_final	*struct_init(t_token **token)
{
	t_token	*node;
	t_final	*final;
	t_final	*tmp;
	int		opt_index;
	int		files_index;

	(1) && (node = *token, final = NULL, files_index = -1);
	while (node)
	{
		if (node == *token || node->type == PIPE)
		{
			(1) && (opt_index = 0, files_index = 0);
			move_next_node(&node);
			tmp = init_final(&node);
			if (!tmp)
				return (NULL);
			node_process(&node, &tmp, &opt_index, &files_index);
			tmp->next = NULL;
			ft_lstadd_back3_parse(&final, tmp);
		}
		else
			node = node->next;
		post_process_files(&tmp, files_index);
	}
	return (final);
}

// #include "../minishell.h"

// // ls -la < lsls >> slsl -l | cat -e

// void print_final(t_final *final) {
//     int i = 0;

//     if (!final) {
//         printf("Final struct is NULL\n");
//         return;
//     }

//     printf("Command: %s\n", final->cmd ? final->cmd : "NULL");

//     printf("Options:\n");
//     if (final->args && final->args[i] && final->args[i][0])
// 	{
//         while (final->args && final->args[i] != NULL && final->args[i][0])
// 		{
// 				// printf("  %s\n", final->args[i]);
// 				puts(final->args[i]);
//             // printf("  %s\n", final->args[i]);
// 			i++;
//         }
//         if (i == 0) {
//             printf("  NULL\n");
//         }
//     } else {
//         printf("  NULL\n");
//     }

//     printf("Input Files:\n");
//     if (final->in_file) {
//         for (i = 0; final->in_file[i]; i++) {
//             printf("  %s\n", final->in_file[i]);
//         }
//         if (i == 0) {
//             printf("  NULL\n");
//         }
//     } else {
//         printf("  NULL\n");
//     }

//     printf("Output Files:\n");
//     if (final->out_file) {
//         for (i = 0; final->out_file[i]; i++) {
//             printf("  %s\n", final->out_file[i]);
//         }
//         if (i == 0) {
//             printf("  NULL\n");
//         }
//     } else {
//         printf("  NULL\n");
//     }

//     printf("Append Output Files:\n");
//     if (final->aout_file) {
//         for (i = 0; final->aout_file[i]; i++) {
//             printf("  %s\n", final->aout_file[i]);
//         }
//         if (i == 0) {
//             printf("  NULL\n");
//         }
//     } else {
//         printf("  NULL\n");
//     }

//     printf("Delimiter:\n");
//     if (final->heredoc) {
//         for (i = 0; final->heredoc[i]; i++) {
//             printf("  %s\n", final->heredoc[i]);
//         }
//         if (i == 0) {
//             printf("  NULL\n");
//         }
//     } else {
//         printf("  NULL\n");
//     }
// }

// int	count_len(t_token *node, int type)
// {
// 	int	i;

// 	i = 0;
// 	while (node && node->type != PIPE)
// 	{
// 		if (node->type == type)
// 			i++;
// 		node = node->next;
// 	}
// 	return (i);
// }

// t_final	*init_final(t_token **nodee)
// {
// 	t_final	*final;
// 	t_token	*node;

// 	node = *nodee;
// 	final = malloc(sizeof(t_final));
// 	if (!final)
// 		return (NULL);
// 	final->cmd = NULL;
// 	if (count_len(node, OPTION) > 0)
// 	{
// 		final->args = malloc(sizeof(char *) * (count_len(node, OPTION) + 1));
// 		if (!final->args)
// 			return (NULL);
// 		final->args[count_len(node, OPTION)] = NULL;
// 	}
// 	else
// 		final->args = NULL;
// 	if (count_len(node, IN_FILE) > 0)
// 	{
// 		final->in_file = malloc(sizeof(char *) * (count_len(node, IN_FILE) + 1));
// 		if (!final->in_file)
// 			return (NULL);
// 		final->in_file[count_len(node, IN_FILE)] = NULL;
// 	}
// 	else
// 		final->in_file = NULL;
// 	if (count_len(node, OUT_FILE) > 0)
// 	{
// 		final->out_file = malloc(sizeof(char *) * (count_len(node, OUT_FILE) + 1));
// 		if (!final->out_file)
// 			return (NULL);
// 		final->out_file[count_len(node, OUT_FILE)] = NULL;
// 	}
// 	else
// 		final->out_file = NULL;
// 	if (count_len(node, AOUT_FILE) > 0)
// 	{
// 		final->aout_file = malloc(sizeof(char *) * (count_len(node, AOUT_FILE) + 1));
// 		if (!final->aout_file)
// 			return (NULL);
// 		final->aout_file[count_len(node, AOUT_FILE)] = NULL;
// 	}
// 	else
// 		final->aout_file = NULL;
// 	if (count_len(node, REDIR_HEREDOC) > 0)
// 	{
// 		final->heredoc = malloc(sizeof(char *) * (count_len(node, DELIMITER) + 1));
// 		if (!final->heredoc)
// 			return (NULL);
// 		final->heredoc[count_len(node, DELIMITER)] = NULL;
// 	}
// 	else
// 		final->heredoc = NULL;
// 	return (final);
// }


// t_final	*struct_init(t_token **token)
// {
// 	t_token *node;
// 	t_final *final;
// 	int 	i;
// 	int		opt_index;
// 	int     in_index;
// 	int     out_index;
// 	int     aout_index;
// 	int     heredoc_index;

// 	node = *token;
// 	while (node)
// 	{
// 		(1) && (i = 0, opt_index = 0, in_index = 0, out_index = 0, aout_index = 0, heredoc_index = 0);
// 		if (node == *token || node->type == PIPE)
// 		{
// 			if (node->type == PIPE)
// 				node = node->next;
// 			final = init_final(&node);
// 			if (!final)
// 				return (NULL);
// 			while (node && node->type != PIPE)
// 			{
// 				if (node->type == CMD)
// 					final->cmd = ft_strdup(node->token);
// 				else if (node->type == OPTION)
// 				{
// 					final->args[opt_index++] = ft_strdup(node->token);
// 				}
// 				else if (node->type == IN_FILE)
// 					final->in_file[in_index++] = ft_strdup(node->token);
// 				else if (node->type == OUT_FILE)
// 					final->out_file[out_index++] = ft_strdup(node->token);
// 				else if (node->type == AOUT_FILE)
// 					final->aout_file[aout_index++] = ft_strdup(node->token);
// 				else if (node->type == DELIMITER)
// 					final->heredoc[heredoc_index++] = ft_strdup(node->token);
// 				node = node->next;
// 			}
// 			print_final(final);
// 		}
// 		else
// 			node = node->next;
// 	}
// 	return (final);
// }
