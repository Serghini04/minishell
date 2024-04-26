/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duping_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:56:54 by hidriouc          #+#    #+#             */
/*   Updated: 2024/04/26 14:57:03 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	creat_pipe(int *T)
{
	if (pipe(T) == -1)
		(perror("piping probleme !!"), exit(EXIT_FAILURE));
}
void	duping_fd(t_mini *data, t_fd *fd)

{
	fd->p_fdin = dup(0);
	fd->p_fdout = dup(1);
	if ((data)->fd_in == -1 || (data)->fd_out == -1 )
		{
			ft_putstr_fd("bash: ", 2);
			ft_putstr_fd((data)->cmd[1], 2);
			ft_putstr_fd(" ...: No such file or directory\n", 2);
		}
	if (data->fd_in > 0)
	{
		close(fd->fdin);
		fd->fdin = data->fd_in;
	}
	if(fd->fdin > 0)
	{
		dup2(fd->fdin, 0);
		close(fd->fdin);
	}
	if (data->next)
	{
		creat_pipe((fd)->t_fd);
		dup2(fd->t_fd[1], 1);
		close (fd->t_fd[1]);
		fd->fdin = fd->t_fd[0];
	}
	if (data->fd_out != 1)
	{
		fd->fdout = data->fd_out;
		if (fd->fdout != 1)
		{
			dup2(fd->fdout, 1);
			close(fd->fdout);
		}
	}
}
