/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_pross.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:53:18 by hidriouc          #+#    #+#             */
/*   Updated: 2024/05/27 16:47:43 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_creat_pross(t_mini *data, t_fd *fd, t_env **env, struct termios *s)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(data);
	fd->pid = malloc(size * sizeof(pid_t));
	if (!fd->pid)
		return ;
	while (data)
	{
		data->env = creat_tabenv(*env);
		(duping_fd(data, fd), fd->pid[i] = fork());
		if (!ft_handel_prossid(data, fd, i, env))
			break ;
		(free_arr(data->env), red_fd_parent(fd), data = data->next);
		i++;
	}
	signal(SIGINT, handl_sig);
	signal(SIGQUIT, SIG_IGN);
	(return_status(fd->pid, i - 1), free (fd->pid));
	if (ft_atoi(save_exit_status(NULL)) == 131)
		attribute_quit(*s);
}