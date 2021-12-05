/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorefor <amorefor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:59:10 by amorefor          #+#    #+#             */
/*   Updated: 2021/09/12 10:59:16 by amorefor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (&str[i]);
}

static int	ft_probraz(const char *str, long int n, int znak, int i)
{
	if (str[i] == '-')
	{
		i++;
		if (str[i] == '+')
			return (0);
		n = -n;
		znak = -1;
	}
	if (str[i] == '+')
		i++;
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (n > 2147483647)
		{
			if (znak == -1)
				return (0);
			return (-1);
		}
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return (n * znak);
}

int	ft_atoi(const char *str)
{
	long int	n;
	int			i;
	int			znak;

	znak = 1;
	n = 0;
	i = 0;
	str = ft_isspace(str);
	n = ft_probraz(str, n, znak, i);
	return (n);
}
