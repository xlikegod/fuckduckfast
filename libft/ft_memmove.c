/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorefor <amorefor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:01:47 by amorefor          #+#    #+#             */
/*   Updated: 2021/09/12 11:01:48 by amorefor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char		*str2;
	unsigned char			*str1;
	size_t					i;

	str1 = (unsigned char *)dst;
	str2 = (const unsigned char *)src;
	i = 0;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str1 < str2)
	{
		i = len;
		while (i > 0)
		{
			str1[len - i] = str2[len - i];
			i--;
		}
	}
	else
	{
		while (i++ != len)
			str1[len - i] = str2[len - i];
	}
	return (str1);
}
