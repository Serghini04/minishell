/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidriouc <hidriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:57:18 by hidriouc          #+#    #+#             */
/*   Updated: 2024/05/12 09:05:52 by hidriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_env(char **env)
{
	int	i;
	int	j;

	i = 0;
	if (!env || !*env)
	{
		ft_putstr_fd("bash : env: no such file or directory\n", 2);
		return ;
	}
	i = 0;
	while (env[i])
	{
		j = 0;
		while(env[i][j])
			j++;
		if(env[i][j - 1] != '.')
		{
			ft_putstr_fd(env[i], 1);
			ft_putstr_fd("\n", 1);
		}
		i++;
	}
}