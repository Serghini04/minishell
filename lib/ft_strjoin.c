/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:12:50 by meserghi          #+#    #+#             */
/*   Updated: 2024/04/10 20:06:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && s2)
		return (s2);
	else if (!s2 && s1)
		return (s1);
	if (!s1 || !s2)
		return (ft_strdup(""));
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
