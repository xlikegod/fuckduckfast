/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorefor <amorefor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:02:28 by amorefor          #+#    #+#             */
/*   Updated: 2021/09/12 11:02:29 by amorefor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (malloc(sizeof(char) * ft_strlen(s1) + 1));
	if (str == NULL)
		return (NULL);
	else
	{
		while (i <= ft_strlen(s1))
		{
			str[i] = s1[i];
			i++;
		}
	}
	return (str);
}
