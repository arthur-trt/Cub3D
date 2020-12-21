/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:19:18 by atrouill          #+#    #+#             */
/*   Updated: 2020/12/15 14:51:32 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_clean_str(char *str)
{
	int		i;
	int		j;

	if (!*str)
		return (str);
	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' '))
		i++;
	j = ft_strlen(str);
	j != 0 ? j -= 1 : 0;
	while (str[j] == '\t' || str[j] == '\n' || str[j] == '\r' ||
			str[j] == '\v' || str[j] == '\f' || str[j] == ' ')
		j--;
	str[++j] = '\0';
	j = 0;
	while ((str + i)[j] != 0)
	{
		if ((str + i)[j] == '\t')
			(str + i)[j] = ' ';
		j++;
	}
	return ((char *)(str + i));
}

int		is_cub_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (ft_strncmp(filename + (len - 4), ".cub", 5) != 0)
		return (ERROR);
	return (SUCCESS);
}
