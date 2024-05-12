/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:23:39 by meserghi          #+#    #+#             */
/*   Updated: 2024/05/12 11:20:29 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f(void)
{
	system("leaks minishell");
}

t_env	*save_env(t_env *env)
{
	static t_env *new_env;

	if (env)
		new_env = env;
	return (new_env);
}

int	main(int ac, char **av, char **env)
{
	t_mini	*data;
	char	*res;
	int		flag;
	t_env	*head;

	(void)av;
	flag = 0;
	save_exit_status(ft_strdup("0"));
	if (ac != 1)
		exit(EXIT_FAILURE);
	data = NULL;
	head = NULL;
	creat_myenv(&head, env);
	while (1)
	{
		res = readline("hi me>> ");
		if (!res)
			break ;
		if (*res)
			add_history(res);
		save_env(head);
		data = parsing_part(res);
		// print_t_mini(data);
		if(data)
			main_process(data, head);
		clear_t_mini(&data);
	}
	printf("exit\n");
	atexit(f);
	return (0);
}
