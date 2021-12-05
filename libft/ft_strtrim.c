/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorefor <amorefor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:03:18 by amorefor          #+#    #+#             */
/*   Updated: 2021/09/12 11:03:19 by amorefor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	set_len = ft_strlen(set);
	while (*s1)
	{
		if (ft_memchr(set, *s1, set_len) == 0)
			break ;
		s1++;
	}
	len = ft_strlen(s1);
	while (len > 0)
	{
		if (ft_memchr(set, s1[len - 1], set_len) == 0)
			break ;
		len--;
	}
	return (ft_substr(s1, 0, len));
}
