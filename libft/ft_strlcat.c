/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorefor <amorefor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:02:38 by amorefor          #+#    #+#             */
/*   Updated: 2021/09/12 11:02:44 by amorefor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t				i;
	size_t				j;

	i = ft_strlen(dst);
	j = 0;
	if (src[j] == '\0')
		return (ft_strlen(dst));
	if (i >= dstsize)
	{
		j = ft_strlen(src);
		return (j + dstsize);
	}
	else
	{
		while (i < dstsize - 1 && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (i + ft_strlen(src) - j);
}
